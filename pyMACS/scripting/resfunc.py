import numpy as np
import numpy.linalg as la

import glob 
import sys
import itertools
import lmfit
import time
import copy
from lmfit import Model, Parameters
import matplotlib.pyplot as plt
# constants
import matplotlib
import sys
from importlib.resources import files
import os

matplotlib.rc("text", usetex=False)
sig2hwhm = np.sqrt(2. * np.log(2.))
sig2fwhm = 2.*sig2hwhm

def descr_ellipse(quadric):
	"""
	Helper function for resolution function calculation. Projects resolution matrix to ellipsoids.
	:param _E: Resolution matrix.
	:type _E: np.ndarray, required
	:param idx: Axis index.
	:type idx: int, required
	:return: [fwhms, angles, eigenvectors], The resolution ellipsoid full width at half maximum, polar angle, and eigenvectors associated with the covariance matrix.
	:rtype: [np.ndarray,np.ndarray,list]
	"""
	[ evals, evecs ] = la.eig(quadric)
	#print("Evals: %s" % evals)

	fwhms = 1./np.sqrt(np.abs(evals)) * sig2fwhm

	angles = np.array([])
	if len(quadric) == 2:
		#Handle unusual case of imaginary eigenvecs
		angles = np.array([ np.arctan2(np.linalg.norm(evecs[1][0]), np.linalg.norm(evecs[0][0])) ])
	return [fwhms, angles/np.pi*180., evecs]

def proj_quad(_E, idx):
	"""
	Helper function for resolution function calculation. Projects resolution matrix to ellipsoids.
	:param _E: Resolution matrix.
	:type _E: np.ndarray, required
	:param idx: Axis index.
	:type idx: int, required
	:return: E, projected ellipsoid
	:rtype: np.ndarray
	"""
	E = np.delete(np.delete(_E, idx, axis=0), idx, axis=1)
	if np.abs(_E[idx, idx]) < 1e-8:
		return E

	v = (_E[idx,:] + _E[:,idx]) * 0.5
	vv = np.outer(v, v) / _E[idx, idx]
	vv = np.delete(np.delete(vv, idx, axis=0), idx, axis=1)

	return E - vv

def hkl_to_labframe(h,k,l,macs):
	"""
	Helper function for resolution function calculation, takes the h,k,l indices and a macs instrument object and converts to Qx, Qz. 

	:param h: Miller h index. Non-integer values allowed.
	:type h: float, required
	:param k: Miller k index.
	:type k: float, required
	:param l: Miller l index.
	:type l: float, required
	:param macs: pyMACS instrument object.
	:type macs: virtualMacs, required
	:return: Qx, Qz, where x is defined as perpendicular to beam and z is along beam.
	:rtype: float,float
	"""
	Qu_vec = macs.sample.astar_vec_labframe*h 
	Qv_vec = macs.sample.bstar_vec_labframe*k  
	Qw_vec = macs.sample.cstar_vec_labframe*l
	Qnet = Qu_vec+Qv_vec+Qw_vec
	if np.linalg.norm(Qnet[1])>0.2:
		print("WARNING: Specified lattice vector does not lie in the scattering plane of the instrument.")
	Qx,Qz = Qnet[0],Qnet[2]
	return Qx,Qz

def calc_ellipses(Qres_Q,verbose=True):
	"""
	Helper function for resolution function calculation, Requires a resolution ellipsoid. 

	:param h: Miller h index. Non-integer values allowed.
	:type h: float, required
	:param verbose: Prints output with resolution info to terminal. 
	:type verbose: bool, optional.
	:return: results,M_proj, these are the results dictionary containing the resolution ellipsoid info for the Qx-Qz plane, the Qx-E plane, and the Qz-E plane. M_proj is the projected resolution matrix on each plane. 
	:rtype: dict, np.ndarray
	"""
	[fwhms, angles, rot] = descr_ellipse(Qres_Q)

	axes_to_delete = [ [2,2], [1,1], [0,0] ]
	slice_first = [ True, True, True]
	results = []

	for ellidx in range(len(axes_to_delete)):
		# sliced 2d ellipse
		Qres = np.delete(Qres_Q, axes_to_delete[ellidx][0], axis=0)
		Qres  = np.delete(Qres, axes_to_delete[ellidx][1], axis=1)

		[fwhms, angles, rot] = descr_ellipse(Qres)
		# projected 2d ellipse
		if slice_first[ellidx]:
			Qres_proj = np.copy(Qres_Q)
			#Qres_proj = np.delete(Qres_proj, axes_to_delete[ellidx][0], axis=0)
			#Qres_proj = np.delete(Qres_proj,axes_to_delete[ellidx][1], axis=1)
			Qres_proj = proj_quad(Qres_proj, axes_to_delete[ellidx][0])
		else:
			Qres_proj = proj_quad(Qres_Q, axes_to_delete[ellidx][0])
			#Qres_proj = np.delete(Qres_Q, axes_to_delete[ellidx][1], axis=0)
			#Qres_proj = np.delete(Qres_proj,axes_to_delete[ellidx][1], axis=1)

		[fwhms_proj, angles_proj, rot_proj] = descr_ellipse(Qres_proj)
		results.append({ "fwhms" : fwhms, "angles" : angles, "rot" : rot,
			"fwhms_proj" : fwhms_proj, "angles_proj" : angles_proj, "rot_proj" : rot_proj })
	Qres_proj = proj_quad(proj_quad(Qres_Q, 1), 0)

	if verbose is True:
		print("3d resolution ellipsoid diagonal elements fwhm (coherent-elastic scattering) lengths:\n%s\n" \
			% (1./np.sqrt(np.abs(np.diag(Qres_Q))) * sig2fwhm))

		print("3d resolution ellipsoid principal axes fwhm: %s" % fwhms)

		Qres_proj = proj_quad(proj_quad(Qres_Q, 1), 0)
		print("Incoherent-elastic fwhm: %.4f meV\n" % (1./np.sqrt(np.abs(Qres_proj[0,0])) * sig2fwhm))

		print("Qx,E sliced ellipse fwhm and slope angle: %s, %.4f" % (results[0]["fwhms"], results[0]["angles"][0]))
		print("Qz,E sliced ellipse fwhm and slope angle: %s, %.4f" % (results[1]["fwhms"], results[1]["angles"][0]))
		print("Qx,Qy sliced ellipse fwhm and slope angle: %s, %.4f" % (results[2]["fwhms"], results[2]["angles"][0]))
		print()
		print("Qx,E projected ellipse fwhm and slope angle: %s, %.4f" % (results[0]["fwhms_proj"], results[0]["angles_proj"][0]))
		print("Qz,E projected ellipse fwhm and slope angle: %s, %.4f" % (results[1]["fwhms_proj"], results[1]["angles_proj"][0]))
		print("Qx,Qy projected ellipse fwhm and slope angle: %s, %.4f" % (results[2]["fwhms_proj"], results[2]["angles_proj"][0]))
	Qres_Q = np.copy(Qres_Q)
	Qres_proj = np.copy(Qres_proj)
	return results,Qres_proj


def nearest_MACS_resfunc(h,k,l,E,macsEf,gen_plot=False,figdir='Calculated_ellipsoid_pngs/',macs_obj=None,verbose=True,macs_dirac_obj=None,calc_mode="default",return_ellips=False):
	"""
	Using a prevoiusly calculated database of resolution ellipsoids, returns the nearest ellipsoid to the input h,k,l,energy point. Can optionally 
	:param h: Miller h index. Non-integer values allowed.
	:type h: float, required
	:param k: Miller k index.
	:type k: float, required
	:param l: Miller l index.
	:type l: float, required
	:param E: Energy transfer (meV)
	:type E: float, required
	:param macsEf: MACS final energy setting, only 3.7 and 5.0 meV are currently supported.
	:type macsEf: float, required.
	:param gen_plot: Flag to trigger creation of figure summarizing the MACS resolution ellipsoid.
	:type gen_plot: bool, optional.
	:param figdir: Output folder to save summary of resolution ellipsoid. 
	:type figdir: str, optional
	:param macs_obj: If the user supplies a pyMACS object, the input sample coordinate system will be used rather than the Qx, Qz frame in Ang^-1. 
	:type macs_obj: virtualMACS, optional
	:param verbose: Flag to print resoultion ellipsoid information to terminal.
	:type verbose: bool, optional.
	:param macs_dirac_obj: Input virtualMACS object using the Qx, Qz frame. User shouldn't touch this. 
	:type macs_dirac_obj: virtualMACS, optional
	:param calc_mode: There are three options, "default", "load_cov", and "Covariance". Users should only use "load_cov", or "default" if they have the correct csv files available. "Covariance" was a developer option, and returns just the covariance matrix.
	:type calc_mode: str, optional.
	:param return_ellips: Flag to return projected resolution ellipsoids to overplot on data rather than full matrix.
	:type return_ellips: bool, optional.

	:return: Qres_Q,[fwhm_M[0],fwhm_M[1],fwhm_M_Eres],[hpt,kpt,wpt]. A list of the resolution ellipsoid M, The Bragg fwhms in Qx (Ang^-1), Qz (Ang^-1), E (meV), and the value of the closest tabulated point in (Qx,Qz,E).
	:rtype: dict, np.ndarray
	"""
	startA = time.time()
	macs=macs_obj
	orig_macs = copy.copy(macs_obj)
	Qmag_ref = macs.sample.Qmag_HKL(h,k,l)

	target_sqw4_dir=str(files("pyMACS.scripting"))+'/ellipsoid_sqw4_files/'
	sqw4_f = glob.glob(target_sqw4_dir+'*.sqw4')
	omegas = []
	#First get a list of omegas in the sqw4 files.
	for f in sqw4_f:
		#Note that the Ei in this filename is for the center of the delta function.
		fstr = f.split('_')
		Ei_ind = fstr.index('Ei')
		Ef_ind = fstr.index('Ef')
		Ei = float(fstr[Ei_ind+1].replace('.sqw4',''))
		Ef = float(fstr[Ef_ind+1].replace('.sqw4',''))
		omega = Ei-Ef
		if np.abs(Ef-macsEf)<0.1:
			omegas.append(Ei)
	omegas = np.array(omegas)
	omegas = np.sort(omegas)
	# Need to find the bin that the specified point falls in
	if len(omegas)>=2:
		delE = np.abs(omegas[1]-omegas[0])/2
	elif len(omegas)==1:
		delE = 0.25
	else:
		print("WARNING: No omegas found.")
		delE=0.3
	sqw4_f_ei = [] # List of files with correct Ei
	for f in sqw4_f:
		fstr = f.split('_')
		Ei_ind = fstr.index('Ei')
		Ef_ind = fstr.index('Ef')
		Ei = float(fstr[Ei_ind+1].replace('.sqw4',''))
		Ef = float(fstr[Ef_ind+1].replace('.sqw4',''))
		omega = Ei-Ef
		if np.abs(omega-E)==delE:
			#This causes bad behavior. Change the E to be slightly lower.
			E-=delE/10.0
		if np.abs(macsEf - Ef)<0.02 and np.abs(omega-E)<delE*1.0:
			sqw4_f_ei.append(f)

	#At this point we should have two files if the point selected falls in a bin,
	# one if on or beyond the edge cases.

	if len(sqw4_f_ei)<1:
		print("ERROR: Specified energy transfer is not accessible.")

	#Gather the relevant files:
	sqw4pts=0
	if len(sqw4_f_ei)==1:
		sqw4pts = np.genfromtxt(sqw4_f_ei[0])
	elif len(sqw4_f_ei)==2:
		#expected case 
		sqw4pts_0 = np.genfromtxt(sqw4_f_ei[0])
		sqw4pts_1 = np.genfromtxt(sqw4_f_ei[1])
		sqw4pts = np.concatenate((sqw4pts_0,sqw4pts_1),axis=0)
	#Get the nearest points in each dimension. 
	#The res sample was oriented in the qu=[1,0,0], qv=[0,1,0] plane
	hpts = np.sort(np.unique(sqw4pts[:,0]))
	wpts = np.sort(np.unique(sqw4pts[:,3]))
	if len(hpts)>1:
		hres =np.abs(hpts[1]-hpts[0])
	else:
		print("Error: Something wrong with the tabulated delta functions.")
	if len(wpts)>1:
		wres = np.abs(wpts[1]-wpts[0])
	else:
		#Have picked a point on the boundary/outside of final bin.
		wres = np.abs(omegas[1]-omegas[0])

	#The sample indices are not the same as Qx, Qy, which is how the sample is defined. 
	h_i = np.where(np.abs(hpts-Qmag_ref)<=hres*0.99)[0]
	w_i = np.where(np.abs(wpts-E)<=wres*0.99)[0]
	#At the end we will re-translate into the sample hkl frame. 
	h_calc_pts = hpts[h_i]
	E_calc_pts = wpts[w_i]
	qxpt,qzpt = hkl_to_labframe(h,k,l,orig_macs)

	macs = macs_dirac_obj
	#Also need to find the rotation required in the Qx/Qz plane.
	if verbose is True:
		print(f"\n Qx, Qz, for hkl = {[qxpt,qzpt]}")
	h0,k0 = qxpt,qzpt
	phi_hkl = np.arctan2(qzpt,qxpt)

	#Now, recover the nearest calculated resolution ellipsoids, then rotate by phi. 
	calc_pts = np.array(list(itertools.product(h_calc_pts,E_calc_pts)))
	#Load the data matrixes for the Ei's assosciated with these points.
	csvdir = str(files("pyMACS.scripting"))+"/ellipsoid_csv_files/"
	macs.data.kidney_result_dir=''
	macs.data.exptName=''
	csvnames = glob.glob(csvdir+"*.csv")

	#Find the files with the correct Ei, Ef
	num_f = 0 
	load_f_dict = {}
	macs.data.data_matrix=False
	for f in csvnames:
		fstr = f.split('_')
		Ef_ind = fstr.index('Ef')
		Ef = float(fstr[Ef_ind+1])
		omega_ind = fstr.index("omega")
		target_omega = float(fstr[omega_ind+1])
		#Check if the omega satisfies any calculated points.

		if np.abs(Ef-macsEf)<0.1 and target_omega in calc_pts[:,1]:
			f_load = f.split('/')[-1]
			num_f+=1
			if macs.data.data_matrix is False:
				#macs.data.load_data_matrix_from_csv(f_load)
				macs.data.kidney_result_dir='ellipsoid_csv_files/'
				fkey = f"Ef_{Ef:.2f}_omega_{target_omega:.2f}"
				load_f_dict[fkey]=f_load
			else:
				#macs.data.append_data_matrix_from_csv(f_load)
				pass
	ellipsoid_dict = {}
	ellip_result_dict = {}
	d_mods_dict = {}
	d_mods = [] #Get the distance from the desired point from the calculated points. 
	result_keys = []
	Qmag_pt = macs.sample.Qmag_HKL(h,k,l)

	for i,pt in enumerate(calc_pts):
		dx = np.abs(Qmag_pt-pt[0])
		dw = np.abs(E - pt[1])
		d = np.linalg.norm([dx/3,dw]) #Factor of 3 is to arbitrarily weight energy higher
		d_mods.append(d)
		d_mods_dict[str(pt)]=d
	d_mods = np.array(d_mods)
	if gen_plot is True:
		plt.rcParams['font.size']=10
		plt.rcParams['xtick.labelsize']=8
		plt.rcParams['ytick.labelsize']=8

	mini = np.argmin(d_mods)
	ptmin = calc_pts[mini]
	# only load the closest point.
	hpt,wpt = ptmin[0],ptmin[1]
	hpt_0, wpt_0 = np.copy(hpt),np.copy(wpt)
	fkey = f"Ef_{macsEf:.2f}_omega_{wpt:.2f}"
	if calc_mode == "default":
		f_load = load_f_dict[fkey]
	if macs.data.data_matrix is False and calc_mode != "load_cov":
		macs.data.load_data_matrix_from_csv(f_load)
	elif calc_mode!="load_cov":
		macs.data.data_matrix=False
		macs.data.load_data_matrix_from_csv(f_load)
	else:
		macs.data.data_matrix=False


	hpt,wpt = ptmin[0],ptmin[1]
	R = np.array([[np.cos(phi_hkl),np.sin(phi_hkl)],[np.sin(phi_hkl),np.cos(phi_hkl)]])
	R_m = np.array([[np.cos(-phi_hkl),np.sin(-phi_hkl)],[np.sin(-phi_hkl),np.cos(-phi_hkl)]])
	hpt,kpt = np.matmul(R,np.array([hpt,0]))

	#Slices integrated in each direction. 
	kres=hres
	if gen_plot is True:
		fig,ax = plt.subplots(1,4,figsize=(3.54*3,3))
		fig.subplots_adjust(hspace=0.6,wspace=0.6)
		#ax[0].set_aspect(1)


	#We handle the rotation by changing the supplied orientation vectors, as follows:
	u_vec = np.copy(macs.sample.orient_u)
	v_vec = np.copy(macs.sample.orient_v)
	orig_u_vec = np.copy(orig_macs.sample.orient_u)
	orig_v_vec = np.copy(orig_macs.sample.orient_v)

	mag_Qu_orig = orig_macs.sample.Qmag_HKL(orig_u_vec[0],orig_u_vec[1],orig_u_vec[2])
	mag_Qv_orig = orig_macs.sample.Qmag_HKL(orig_v_vec[0],orig_v_vec[1],orig_v_vec[2])

	#Get the polar angle associated withthe point. 	
	urot = np.array([qxpt,qzpt,0])
	urot = urot/np.linalg.norm(urot)
	phi_perp = np.pi/2
	perpR = np.array([[np.cos(phi_perp),-np.sin(phi_perp)],[np.sin(phi_perp),np.cos(phi_perp)]])
	vrot = np.matmul(perpR,np.array([urot[0],urot[1]]))
	vrot = np.array([vrot[0],vrot[1],0])
	#These are in the lab frame. Need to reset in terms of the original sample u-v vectors


	#Reset the projection.
	macs.data.projected_matrix=False
	macs.sample.project_sample_realspace()
	macs.data.sample=macs.sample
	if calc_mode!="load_cov":
		macs.data.project_data_QE(viewing_axes=[urot,vrot])

	#frac=0.04
	#nQ = 150
	if calc_mode != "load_cov":
		Eipts = np.unique(macs.data.data_matrix['Ei'])

		Eipts = Eipts[np.abs(Eipts- macsEf-wpt)<=wres]

		numE = len(Eipts)+1
		minE = np.min(Eipts)-macsEf
		maxE = np.max(Eipts)-macsEf
		minE-=0.01
		maxE+=0.01
		frac=2.0
		nQ = 15
		# Originally, point is specified in the h,k,l plane of the sample.
		# Need to go to Qx, Qz plane. 

		print(f"hpt={hpt:.2f}")
		print(f"kpt={kpt:.2f}")
		print(f"MinE={minE:.2f} MaxE={maxE:.2f}")

		Qx_constE,Qz_constE,const_E_slice,const_E_slice_err = \
			macs.data.take_slice([hpt-hres/frac,hpt+hres/frac,nQ],\
			[kpt-kres/frac,kpt+kres/frac,nQ+1],[minE,maxE],smooth=False)
		#print(f"Slice params: {[round(hpt-hres/frac,3),round(hpt+hres/frac,3),nQ],[round(kpt-kres/frac,3),round(kpt+kres/frac,3),nQ+1],[minE,maxE]}")
		Qz_constQx,E_constQx,const_Qx_slice,const_Qx_slice_err = \
			macs.data.take_slice([hpt-hres/frac,hpt+hres/frac],\
				[kpt-kres/frac,kpt+kres/frac,nQ+1],[minE,maxE,numE],smooth=False)
		Qx_constQz,E_constQz,const_Qz_slice,const_Qz_slice_err = \
			macs.data.take_slice([hpt-hres/frac,hpt+hres/frac,nQ+1],\
				[kpt-kres/frac,kpt+kres/frac],[minE,maxE,numE],smooth=False)
		const_Qx_slice,const_Qx_slice_err=const_Qx_slice.T,const_Qx_slice_err.T
		const_Qz_slice,const_Qz_slice_err=const_Qz_slice.T,const_Qz_slice_err.T
		const_E_slice,const_E_slice_err=const_E_slice.T,const_E_slice_err.T
	if gen_plot is True:
		if calc_mode!='load_cov':
			ax[0].pcolormesh(Qx_constE,Qz_constE,const_E_slice,vmin=0,vmax=np.nanmax(const_E_slice),cmap='viridis',rasterized=True)
		ax[0].plot(qxpt,qzpt,marker='o',mfc='w',mec='k')
		ax[0].plot(hpt,kpt,marker='o',mfc='c',mec='k')
		ax[0].set_xlabel(r"$Q_\perp\ (\AA^{-1}$)",labelpad=0,fontsize=8)
		ax[0].set_ylabel(r"$Q_\parallel\ (\AA^{-1}$)",labelpad=0,fontsize=8)
		if calc_mode!='load_cov':
			ax[2].pcolormesh(Qz_constQx,E_constQx,const_Qx_slice,vmin=0,vmax=np.nanmax(const_Qx_slice),cmap='viridis',rasterized=True)
		ax[2].plot(qzpt,E,marker='o',mfc='w',mec='k',label='Input Point')
		ax[2].plot(kpt,wpt,marker='o',mfc='c',mec='k',label='Nearest Stored Point')
		ax[2].set_xlabel(r"$Q_\parallel\ (\AA^{-1}$)",labelpad=0,fontsize=8)
		ax[2].set_ylabel(r"$\hbar\omega$ (meV)",labelpad=0,fontsize=8)
		if calc_mode!='load_cov':
			ax[1].pcolormesh(Qx_constQz,E_constQz,const_Qz_slice,vmin=0,vmax=np.nanmax(const_Qz_slice),cmap='viridis',rasterized=True)
		ax[1].plot(qxpt,E,marker='o',ls=' ',mfc='w',mec='k',label='Input Point')
		ax[1].plot(hpt,wpt,marker='o',ls=' ',mfc='c',mec='k',label='Nearest Stored Point')
		ax[1].set_xlabel(r"$Q_\perp\ (\AA^{-1}$)",labelpad=0,fontsize=8)
		ax[1].set_ylabel(r"$\hbar\omega$ (meV)",labelpad=0,fontsize=8)
		#The figure misbehaves if we don't fix the limits here. 
		if calc_mode!='load_cov':
			ax[0].set_xlim(np.nanmin(Qx_constE),np.nanmax(Qx_constE))
			ax[0].set_ylim(np.nanmin(Qz_constE),np.nanmax(Qz_constE))
			ax[2].set_xlim(np.nanmin(Qz_constQx),np.nanmax(Qz_constQx))
			ax[2].set_ylim(np.nanmin(E_constQx),np.nanmax(E_constQx))
			ax[1].set_xlim(np.nanmin(Qx_constQz),np.nanmax(Qx_constQz))
			ax[1].set_ylim(np.nanmin(E_constQz),np.nanmax(E_constQz))

	#Hide the spines of the last column. 
	if gen_plot is True:
		ax[3].axis('off')
		ax[2].legend(loc=(1.2,0.85),fontsize=8)

	#New: Perform covariance matrix analysis. Structure the data into a [Q,E] 4-vector
	if calc_mode != "load_cov":
		Qx,Qz,En,I,Err = macs.data.take_volume([hpt-hres/frac,hpt+hres/frac,nQ+1],\
				[kpt-kres/frac,kpt+kres/frac,nQ+1],[minE,maxE,numE],smooth=False)

		# Convert the coordinates to bin centers:
		Qx = (Qx[:-1,:-1,:-1] + Qx[1:,1:,1:]) / 2
		Qy = np.copy(Qx)
		Qz = (Qz[:-1,:-1,:-1] + Qz[1:,1:,1:]) / 2
		En = (En[:-1,:-1,:-1] + En[1:,1:,1:]) / 2
	# Define the coordinate system: 
	# We are excluding the y-direction
	Qpara = np.array([0,1])
	Qnorm=Qpara
	Qside = np.array([1,0])
	if calc_mode != "load_cov":
		Q4 = np.array([Qx.flatten(),Qz.flatten(),En.flatten()]).T
		w = I.flatten()
		w[np.isnan(w)]=0
		Qmean = [ np.average(Q4[:,i], weights = w) for i in range(3) ]
	else:
		Qmean = [hpt,kpt,wpt]
	# get the weighted covariance matrix
	if calc_mode != "load_cov":
		Qcov = np.cov(Q4, rowvar = False, aweights = np.abs(w), ddof = 0)
	elif calc_mode == "load_cov":
		#get the filename
		covdir = str(files("pyMACS.scripting"))+"/covariance_matrices/"
		fstr = covdir+ f"h_{hpt_0:.3f}_w_{wpt_0:.2f}_Ef_{macsEf:.1f}_Cov.dat"
		Qcov = np.genfromtxt(fstr)
		w=1.0
		Qmean = [hpt,kpt,wpt]
	if calc_mode == "Covariance":
		return Qcov
	if verbose is True:
		print("Covariance matrix in lab system:\n%s\n" % Qcov)
	# the resolution is the inverse of the covariance
	Qres = la.inv(Qcov)
	if verbose is True:
		print("Resolution matrix in lab system:\n%s\n" % Qres)

	# transform matrix
	T = np.transpose(np.array([
		np.insert(Qnorm, 2, 0),
		np.insert(Qside, 2, 0),
		[0, 0, 1] ]))

	if calc_mode=="load_cov":
		T = np.transpose(np.array([[vrot[0],vrot[1],0],[urot[0],urot[1],0],[0,0,1]]))
		#T = np.transpose(np.array([[urot[0],urot[1],0],[vrot[0],vrot[1],0],[0,0,1]]))
	options={}
	options['verbose']=verbose
	if options["verbose"]:
		print("Transformation into (Qpara, Qperp, E) system:\n%s\n" % T)

	# transform mean Q vector
	Qmean_Q = np.dot(np.transpose(T), Qmean)
	if options["verbose"]:
		print("Mean (Q, E) vector in (Qpara, Qperp, Qup, E) system:\n%s\n" % Qmean_Q)
	Qmean_Q = np.copy(Qmean_Q)
	# transform the covariance matrix
	Qcov_Q = np.dot(np.transpose(T), np.dot(Qcov, T))
	if options["verbose"]:
		print("Covariance matrix in (Qpara, Qperp, E) system:\n%s\n" % Qcov_Q)
	Qcov_Q = np.copy(Qcov_Q)
	# the resolution is the inverse of the covariance
	Qres_Q = la.inv(Qcov_Q)
	if options["verbose"] :
		print("Resolution matrix in (Qpara, Qperp, E) system:\n%s\n" % Qres_Q)
	Qres_Q = np.copy(Qres_Q)
	#[ evals, evecs ] = la.eig(Qcov_Q)
	#print("Ellipsoid fwhm radii:\n%s\n" % (np.sqrt(np.abs(evals)) * sig2fwhm))
	#return [Qres_Q, Q4_Q, Qmean_Q]
	results,Qres_proj = calc_ellipses(Qres_Q,verbose=verbose)

	try:
		import mpl_toolkits.mplot3d as mplot3d
		import matplotlib
		import matplotlib.pyplot as plot
	except ImportError:
		print("Matplotlib could not be imported!")
		exit(-1)
	options['use_tex']=False
	options['symsize']=8
	options['centre_on_Q']=True
	options['plot_results']=True
	options['ellipse_points']=256
	options['dpi']=300
	matplotlib.rc("text", usetex=False)

	thesymsize = options["symsize"] * w
	themarker = "."

	ellfkt = lambda rad, rot, phi, Qmean2d : \
		np.dot(rot, np.array([ rad[0]*np.cos(phi), rad[1]*np.sin(phi) ])) + Qmean2d


	# 2d plots
	#fig = plot.figure()
	ellis = results
	num_ellis = len(ellis)
	coord_axes = [[0,1], [1,2], [0,2]]

	coord_axes = [[0,1], [0,2], [1,2]]
	coord_names = ["Qpara (1/A)", "Qperp (1/A)", "E (meV)"]
	if options["use_tex"]:
		coord_names[0] = "$Q_{\\parallel}$ (\\AA$^{-1}$)"
		coord_names[1] = "$Q_{\\perp}$ (\\AA$^{-1}$)"
		#coord_names[2] = "$Q_{up}$ (\\AA$^{-1}$)"


	ellplots = []
	for ellidx in range(num_ellis):
		# centre plots on zero or mean Q vector ?
		QxE = np.array([[0], [0]])
		QxE = np.array([[Qmean[coord_axes[ellidx][0]]], [Qmean[coord_axes[ellidx][1]]]])

		phi = np.linspace(0, 2.*np.pi, 361)

		ell_QxE = ellfkt(ellis[ellidx]["fwhms"]*0.5, ellis[ellidx]["rot"], phi, QxE)
		ell_QxE_proj = ellfkt(ellis[ellidx]["fwhms_proj"]*0.5, ellis[ellidx]["rot_proj"], phi, QxE)

		#ell_QxE = ellfkt(ellis[ellidx]["fwhms"], ellis[ellidx]["rot"], phi, QxE)
		#ell_QxE_proj = ellfkt(ellis[ellidx]["fwhms_proj"], ellis[ellidx]["rot_proj"], phi, QxE)
		ellplots.append([{"sliced":ell_QxE, "proj":ell_QxE_proj}])

		if gen_plot is True:
			ax[ellidx].plot(ell_QxE[0], ell_QxE[1], c="r", linestyle="dashed")
			ax[ellidx].plot(ell_QxE_proj[0], ell_QxE_proj[1], c="r", linestyle="solid")
			ax[ellidx].set_xlim()

	if return_ellips is True:
		return ellplots
	#plt.tight_layout()
	fwhm_M = np.copy(1./np.sqrt(np.abs(np.diag(Qres_Q))) * sig2fwhm)
	fwhm_M_Eres = np.copy(1./np.sqrt(np.abs(Qres_proj[0,0])) * sig2fwhm)
	#Put some text information regarding the extracted widths, similar to reslib. 
	if gen_plot is True:
		infostr = "MACS Resolution Simulation:\n"+"HF=1 VF=1 "+r"$E_f$"+f"={macsEf:.2f}"+" meV"+f"\n\nRequested point (h,k,l,"+r"$\hbar\omega$"+f"):\n ({h:.1f}, {k:.1f}, {l:.1f}, {E:.1f})"+\
					"\n\nBragg Widths: "+\
					r"$\delta Q_\perp$="+f"{fwhm_M[0]:.3f} "+r"$\AA^{-1}$,"+"\n"+\
					r"$\delta Q_\parallel$="+f"{fwhm_M[1]:.3f} "+r"$\AA^{-1}$,"+\
					r" $\delta \hbar\omega$="+f"{fwhm_M_Eres:.3f}"+r" meV"
	res_matstr = "Resolution Matrix\n"+f"{np.array_str(Qres_Q,precision=2,suppress_small=True)}"

	if gen_plot is True:
		ax[3].text(-0.3,0.3,infostr,transform=ax[3].transAxes,horizontalalignment='left',verticalalignment='bottom',fontsize=8)
	if gen_plot is True:
		ax[3].text(-0.3,0.25,res_matstr,transform=ax[3].transAxes,horizontalalignment='left',verticalalignment='top',fontsize=8)
	if gen_plot is True:
		fig.show()
		try:
			fig.savefig(figdir+f"MACS_resfunc_Ef_{macsEf:.2f}meV_h_{h:.2f}_k_{k:.2f}_l_{l:.2f}_w_{E:.2f}.pdf",dpi=300)
		except Exception as e:
			print(e)
			print("Saving figure failed, ensure that the specfied figure directory exists.")
	return Qres_Q,[fwhm_M[0],fwhm_M[1],fwhm_M_Eres],[hpt,kpt,wpt]


def macs_resfunc(h,k,l,E,macsEf,macsobj=False,gen_plot=True,verbose=False,calc_mode="load_cov",figdir="Calculated_ellipsoid_pngs/",
	return_ellips=False):
	"""
	Main function that recovers the MACS resolution ellipsoid from a pre-calculated set of ellipsoids. 

	:param h: Miller h index. Non-integer values allowed.
	:type h: float, required
	:param k: Miller k index.
	:type k: float, required
	:param l: Miller l index.
	:type l: float, required
	:param E: Energy transfer (meV)
	:type E: float, required
	:param macsEf: MACS final energy setting, only 3.7 and 5.0 meV are currently supported.
	:type macsEf: float, required.
	:param gen_plot: Flag to trigger creation of figure summarizing the MACS resolution ellipsoid.
	:type gen_plot: bool, optional.
	:param macs_obj: If the user supplies a pyMACS object, the input sample coordinate system will be used rather than the Qx, Qz frame in Ang^-1. 
	:type macs_obj: virtualMACS, optional
	:param verbose: Flag to print resoultion ellipsoid information to terminal.
	:type verbose: bool, optional.
	:param calc_mode: There are three options, "default", "load_cov", and "Covariance". Users should only use "load_cov", or "default" if they have the correct csv files available. "Covariance" was a developer option, and returns just the covariance matrix.
	:type calc_mode: str, optional.
	:param return_ellips: Flag to return the projected resolution ellipsoids rather than the full matrix. Useful for plotting. 
	:type return_ellips: bool, optional
	:return: M, M_diag, Q_hkw. The resolution matrix, the diagonal elements / fwhm in Qx, Qz, E, and the (Qx, Qz, E) position of the closest tabulated point.
	:rtype: np.ndarray, np.ndarray, np.ndarray
	"""	
	from pyMACS.virtualMACS import VirtualMACS

	macs_dirac = VirtualMACS('resolution_calculation',cifName=str(files("pyMACS.scripting"))+'/dirac.cif',useOld=False)
	macs_dirac.sample.orient_u=[1,0.0,0]
	macs_dirac.sample.orient_v=[0,1,0]
	macs_dirac.sample.project_sample_realspace()
	if macsobj is False or macsobj is None:
		macs = macs_dirac
	else:
		macs = macsobj
	#macsEf=3.7
	mode='nearest'

	if calc_mode == "Covariance":
		#development option
		Cov = nearest_MACS_resfunc(h,k,l,E,macsEf,gen_plot=gen_plot,figdir=figdir,
		macs_obj=macs,verbose=verbose,macs_dirac_obj=macs_dirac,calc_mode=calc_mode,
		return_ellips=return_ellips)
		return Cov

	else:
		M,M_diag,Q_hkw = nearest_MACS_resfunc(h,k,l,E,macsEf,gen_plot=gen_plot,figdir=figdir,
			macs_obj=macs,verbose=verbose,macs_dirac_obj=macs_dirac,calc_mode=calc_mode,
			return_ellips=return_ellips)
		M_diag = np.copy(M_diag)
	return M,M_diag,Q_hkw


def res_ellipses(M,Qmean,macsobj=None,n_phi=361):
	"""
	Shortcut function to return resollution ellipsoids for a given resolution matrix. Essentially automates the step of projection of the resolution matrix. The projection is in the sample Qx, Qz, E frame.
	The value of the center of the ellipsoid must be specified, Qmean, which is in units of u, v. For example, if u=[1,1,0], v=[0,0,1], and one wants the (1,1,0) reflection, use Qmean=[1,0,0]. If one wants the resolution at the (1,1,0) position and 1 meV transfer, use Qmean = [1,0,1]. If no virtualmacs object is provided, it is assumed that we are using the lab frame. 

	:param M: 3x3 Resolution matrix of the specified point. 
	:type M: np.ndarray, required
	:param Qmean: Center of the resolution ellipsoid, in format [h, k, l, E]. Note that if the input point is not in the scattering plane, this will give wrong results.
	:type Qmean: np.ndarray, required.
	:param macsobj: Virtualmacs object containing sample information and orientation. If not provided, will default to the lab frame and results will be in Ang^-1
	:type macsobj: virtualMACS, optional.
	:return ellip_list,proj_ellip_list: Returns a list contiaining np arrays for each ellipse. The arrays are structured as [[Qxpts,Qzpts],[Qxpts,Epts],[Qzpts,Epts]]
	:rtype: list, list
	"""
	sig2hwhm = np.sqrt(2. * np.log(2.))
	sig2fwhm = 2.*sig2hwhm

	results,Qres_proj = calc_ellipses(M,verbose=False)
	# Ellipsoids were originally calculated in the Qx, Qz, E lab frame. Need to rescale to sample, if one is provided.
	if macsobj is not None:
		Uvec = macsobj.sample.orient_u 
		Vvec = macsobj.sample.orient_v
		magU = macsobj.sample.Qmag_HKL(Uvec[0],Uvec[1],Uvec[2])
		magV = macsobj.sample.Qmag_HKL(Vvec[0],Vvec[1],Vvec[2])
		Qxscale = 1.0/magU
		Qzscale = 1.0/magV
		Escale = 1.0
	else:
		Qxscale = 1.0
		Qzscale =1.0
		Escale =1.0
	#Convert Qmean from H,K,L to Qu, Qv
	Qmean_lab = macsobj.sample.astar_vec_labframe*Qmean[0]+\
				macsobj.sample.bstar_vec_labframe*Qmean[1]+\
				macsobj.sample.cstar_vec_labframe*Qmean[2]
	Qu_lab = hkl_to_labframe(macsobj.sample.orient_u[0],
							macsobj.sample.orient_u[1],
							macsobj.sample.orient_u[2],macsobj)
	Qv_lab = hkl_to_labframe(macsobj.sample.orient_v[0],
							macsobj.sample.orient_v[1],
							macsobj.sample.orient_v[2],macsobj)
	mag_Qu = np.linalg.norm(Qu_lab)
	mag_Qv = np.linalg.norm(Qv_lab)

	Qmean_lab_rot = np.array([Qmean_lab[0],Qmean_lab[2]])
	#Put in terms of Qu, Qv using a change of basis
	M = np.array([[Qu_lab[0],Qv_lab[0]],[Qu_lab[1],Qv_lab[1]]])
	B_mat = np.matmul(np.linalg.inv(np.matmul(M.T,M)),M.T)
	Q_u1u2 = np.matmul(B_mat,Qmean_lab_rot)
	print(f"Q_u1u2={Q_u1u2}")
	U1_proj=Q_u1u2[0]
	U2_proj = Q_u1u2[1]
	U_proj = U1_proj
	V_proj = U2_proj
	Qmean = np.array([U_proj,V_proj,Qmean[3]])
	ellfkt_factor = 0.5 # In mccode it is 0.5
	ellfkt = lambda rad, rot, phi, xscale,yscale, Qmean2d : \
	    np.dot(rot, np.array([ rad[0]*xscale*np.cos(phi), rad[1]*yscale*np.sin(phi) ])) + Qmean2d


	# 2d plots
	#fig = plot.figure()
	ellis = results
	num_ellis = len(ellis)
	coord_axes = [[0,1], [1,2], [0,2]]

	coord_axes = [[0,1], [0,2], [1,2]]
	ellip_list = []
	proj_ellip_list = []
	ellip_scales = [[Qxscale,Qzscale],[Qxscale,Escale],[Qzscale,Escale]]
	for ellidx in [0,1,2]:
		# centre plots on zero or mean Q vector ?

		QxE = np.array([[Qmean[coord_axes[ellidx][0]]],
	                    [Qmean[coord_axes[ellidx][1]]]])

		phi = np.linspace(0, 2.*np.pi, n_phi)

		ell_QxE = ellfkt(ellis[ellidx]["fwhms"]*ellfkt_factor, ellis[ellidx]["rot"],phi,float(ellip_scales[ellidx][0]),float(ellip_scales[ellidx][1]), QxE)
		ell_QxE_proj = ellfkt(ellis[ellidx]["fwhms_proj"]*ellfkt_factor, ellis[ellidx]["rot_proj"],phi,float(ellip_scales[ellidx][0]),float(ellip_scales[ellidx][1]), QxE)

		ellippts = np.array([ell_QxE[0], ell_QxE[1]])
		ellip_list.append(ellippts)
		projpts=np.array([ell_QxE_proj[0], ell_QxE_proj[1]])
		proj_ellip_list.append(projpts)

	return np.array(ellip_list),np.array(proj_ellip_list)
