import numpy as np
from lmfit import Model,Parameters
import lmfit
import matplotlib.pyplot as plt
class Monochromator(object):
	"""
	This object contains parameters for the monochromator calculation. TODO: beta1/beta2 calcultation

	:param repeat_count=1: How many times the virtual out from MACS_monochromator is used
	:param EM: monochromator energy setting [meV]
	:param HF=1: Horizontal focusing (ALWAYS 1, 0 mode broken)
	:param sample_diameter_d: Sample diameter, can just be left at 0.02
	:param beta_1: Monochromator beta_1 parameter
	:param beta_2: Monocromator beta_2 parameter
	:param slit_h: Slit after guide horizontal [m] Default 0.2
	:param slit_v: Slit after guide vertical [m] Default 0.2

	"""
	def __init__(self,repeat_count=1,Ei=5.0,HF=1,VF=1,beta_1=False,beta_2=False,misalign_deg=0.15,slit_h=0.2,slit_v=0.2,MPL=6.06,MPD=0.775,\
		DIRDEV=0.0,DIVSOU=3.0,L0_delta=-1.06,L1_delta=0.0,mon_t=0.0,mon_e=0.0,monrot_delta=0.0,dmbt=0.02):
		self.repeat_count=repeat_count
		self.Ei = Ei 
		self.HF=HF 
		self.VF=VF
		self.beta_1 = beta_1 
		self.beta_2 = beta_2 
		self.misalign_deg = misalign_deg 
		self.slit_h = slit_h 
		self.slit_v = slit_v 
		self.MPL = MPL 
		self.MPD = MPD 
		self.DIRDEV = DIRDEV 
		self.DIVOU = DIVSOU 
		self.L0_delta = L0_delta
		self.L1_delta=L1_delta 
		self.mon_t = mon_t 
		self.mon_e = mon_e 
		self.monrot_delta = monrot_delta 
		self.dmbt = dmbt #Sample diameter

	def calc_betas(self,ei,dmbt):
		#Imitates MACS IDL script to determine beta1 beta2 for specific dmbt setting
		#Data for DMBT=20
		dmbt *=1e3 #Convert from m to mm
		tt_all = np.array([43.,50.,60.,70.,80.,90.,100.,110.,120.])
		dmbt_all=np.array([5,10,15,20,25.])
		ttc_mat_b1 = np.zeros(len(dmbt_all))
		ttc_mat_b2 = np.zeros(len(dmbt_all))

		beta1_dmbt20 = np.array([0.3,0.45,0.7,0.87,0.87,1.10,1.14,1.20,1.28])
		beta2_dmbt20= np.array( [2.07, 2.02, 2.13, 2.18, 2.32, 2.30, 2.21, 2.07, 2.05])
		beta1_dmbt10 = np.array([0.4, 0.63, 0.8, 0.95, 1.22, 1.29, 1.45, 1.57, 1.58])
		beta2_dmbt10= np.array([1.66,2.08,2.12,2.20,2.23,2.19,2.17,2.07,2.00])

		beta1_dmbt5 = np.array([0.7, 1.19, 1.32, 1.30, 1.40, 1.57, 1.70, 1.71, 2.0])
		beta2_dmbt5 = np.array( [2.28, 2.55, 2.49, 2.69, 2.52, 2.43, 2.44, 2.21, 2.21])

		beta1_dmbt15 = np.array([0.43, 0.41, 0.58, 0.77, 0.95, 1.13, 1.21, 1.43, 1.35])
		beta2_dmbt15 = np.array([2.09, 2.12, 2.22, 2.31, 2.28, 2.17, 2.14, 2.11, 2.02])
		beta1_dmbt25 = np.array([0.1, 0.16, 0.23, 0.58, 0.68, 0.92, 1.08, 1.10, 1.16])
		beta2_dmbt25 = np.array([1.68, 2.14, 2.20, 2.39, 2.23, 2.16, 2.17, 2.01, 1.98])

		allbetas1 = np.array([beta1_dmbt5,beta1_dmbt10,beta1_dmbt15,beta1_dmbt20,beta1_dmbt25])
		allbetas2 = np.array([beta2_dmbt5,beta2_dmbt10,beta2_dmbt15,beta2_dmbt20,beta2_dmbt25])
		dbeta1   = np.array([0.05, 0.03, 0.03, 0.02 ,0.04, 0.03, 0.05, 0.03, 0.04])
		dbeta2   = np.array([0.02, 0.01, 0.01, 0.03, 0.03, 0.02, 0.03, 0.02, 0.02])

		model = lmfit.models.PolynomialModel(degree=5,independent_vars=['x'],nan_policy='raise')
		#Fit betas as a function of tt, with errors specified above.
		weights1 = 1.0/dbeta1
		weights2 = 1.0/dbeta2
		rad2deg = 180.0/np.pi
		taum=1.87325
		ki = np.sqrt(ei/2.072)
		ttc = np.arcsin(taum/(2.0*ki))*rad2deg
		print(ttc)
		weights1 = 1.0/dbeta1
		weights2 = 1.0/dbeta2
		for i in range(len(ttc_mat_b1)):
			pars1 = model.guess(allbetas1[i],x=tt_all)
			pars2 = model.guess(allbetas2[i],x=tt_all)

			result_beta1 = model.fit(allbetas1[i],pars1,x=tt_all,weights=weights1)
			result_beta2 = model.fit(allbetas2[i],pars2,x=tt_all,weights=weights2)
			interp1 = model.eval(x=ttc,params=result_beta1.params)
			interp2 = model.eval(x=ttc,params=result_beta2.params)
			ttc_mat_b1[i]=interp1
			ttc_mat_b2[i]=interp2
			model3 = lmfit.models.PolynomialModel(degree=3,independent_vars=['x'],nan_policy='raise')
			pars3_1 = model3.guess(ttc_mat_b1,x=dmbt_all)
			pars3_2 = model3.guess(ttc_mat_b2,x=dmbt_all)

			result_pbeta1 = model3.fit(ttc_mat_b1,pars3_1,x=dmbt_all)
			result_pbeta2 = model3.fit(ttc_mat_b2,pars3_2,x=dmbt_all)
			beta1c = model3.eval(x=dmbt,params=result_pbeta1.params)
			beta2c = model3.eval(x=dmbt,params=result_pbeta2.params)

		return beta1c,beta2c