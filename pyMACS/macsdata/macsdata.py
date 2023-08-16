import numpy as np
import os
import pandas as pd
import glob
import scipy
from scipy.stats import binned_statistic_2d

class Data(object):
	"""
	Class to handle the results of McStas simulations and compare to 
	experimental data. Also used to convert to ng0 format for Mslice.

	:param exptName: Name assosciated with the experiment.
	:type exptName: str
	:param data_matrix: Huge pandas matrix containing all of the previous results. Store all results in memory to be quickly referenced.
		Gone into in more detail elsewhere in individual functions, but can technically also be accessed directly by users. 
	:type data_matrix: pd.Dataframe
	:param projected_matrix: Results after being projected into Q/E space the viewing axis specified by the sample alignment. 
		Also a pandas dataframe.
	:type projected_matrix: pd.Dataframe
	:param expt_data_matrix: Pandas Dataframe containing all imported experimental results. Convenient to compare to the normal data_matrix
		directly. 
	:type expt_data_matrix: pd.Dataframe
	:param projected_expt_matrix: Experimental data projected into Q/E space using the specified sample orientation. 
	:type projected_expt_matrix: pd.Dataframe
	:param PTAI_det: If PTAI is being used, specifies the detector. 
	:type PTAI_det: int
	:param csv_name: Specifies the name of the .csv file where the cumulative data matrix is stored. 
	:type csv_name: str
	"""
	def __init__(self,sample,exptName=None,kidney_result_dir=None,compile_mode='all',beta_1=1.0,beta_2=1.0,PTAI_det=3):
		#Note the sample object is defined in the same module.
		self.compile_mode=compile_mode #Specifies if output ng0 files should be combined, individual, etc
		self.kidney_sim_dir=None
		self.kidney_result_dir=kidney_result_dir
		if exptName==None:
			exptName='McStas simulation'
		self.exptName=exptName
		self.sample=sample
		self.data_matrix = False #This is a large matrix that is initialized later
		self.projected_matrix = False #Projection into QE space to visualize results. 
		self.expt_data_matrix = False #Imitated data matrix from real ng0 file 
		self.projected_expt_matrix = False #Projection of said data matrix onto Q-space
		self.beta_1=beta_1
		self.beta_2=beta_2
		self.PTAI_det=PTAI_det
		self.csv_name='_dataMatrix.csv' #Specifies name of output file

		#Check if output csv files already exist in the directory. If so, add them all to the data matrix. 
		old_csvs = glob.glob(self.kidney_result_dir+'*.csv')
		if len(old_csvs)>0:
			self.combine_all_csv(fname='_total.csv')
			print('#########################')
			print('Old simulations found in '+self.kidney_result_dir)
			self.load_data_matrix_from_csv(csv_file='_total.csv')
			print(' ')
			print('Successfully combined old simulations into '+self.kidney_result_dir+self.exptName+'_total.csv')
			print('')
			print('Data matrix instantiated and ready to use.')
			print('#########################')
		
	def writeHeader(self,output_file_name):
		output_file = open(output_file_name, 'w')
		output_file.write('#ICE           0.4.0\n')
		output_file.write('#ICERepositoryInfo /ice/server/releases/ALL_2014_05_22 \n')
		output_file.write('#Filename    Simulated MCstas data \n')
		output_file.write('#Date        2016-07-27 17:57:57 EDT \n')
		output_file.write('#InstrName   NG0 \n')
		output_file.write('#Epoch       1469656677.57 \n')
		output_file.write('#ExptID      20160727\n')
		output_file.write('#ExptName    \n')
		output_file.write('#ExptParticipants  \n')
		output_file.write('#ExptDetails \n')
		output_file.write('#ExptComment \n')
		output_file.write('#User        ncnr\n')
		output_file.write('#Comment     \n')
		output_file.write('#TemperatureUnits Kelvin\n')
		output_file.write('#Ncolumns    131\n')
		output_file.write('#DetectorDims 48\n')
		output_file.write('#Signal      8 Monitor\n')
		output_file.write('#Reference   8 Monitor\n')
		output_file.write('#ScanType   ANGLE\n')
		output_file.write('#DetectorEfficiencies SPEC08=1.06822 DIFF08=1.0 SPEC13=1.02982 SPEC=1.0 DIFF12=1.0 DIFF06=1.0 DIFF20=1.0 SPEC18=1.65028 DIFF13=1.0 DIFF14=1.0 DIFF15=1.0 DIFF16=1.0 DIFF17=1.0 DIFF10=1.0 DIFF11=1.0 DIFF18=1.0 DIFF19=1.0 DIFF03=1.0 DIFF02=1.0 DIFF01=1.0 DIFF07=1.0 DIFF05=1.0 DIFF04=1.0 DIFF09=1.0 SPEC19=0.953006 SPARE=1.0 SPEC20=1.02213 Time=1.0 SPEC01=0.8707 SPEC10=0.791158 SPEC11=0.762235 SPEC14=1.15965 SPEC15=1.22142 SPEC16=1.00225 SPEC17=0.82556 SPEC12=0.807705 DIFF=1.0 SPEC06=0.914812 SPEC05=1.05829 SPEC04=0.842027 SPEC03=1.01165 SPEC02=1.06092 SPEC09=1.09363 SPEC07=0.854509 Monitor=1.0 \n')
		output_file.write('#FixedE     Ei 1\n')
		output_file.write('#Lattice     '+str(self.sample.a)+' '+str(self.sample.b)+' '+str(self.sample.c)+' '+str(self.sample.alpha)+' '+\
			str(self.sample.beta)+' '+str(self.sample.gamma)+'\n')
		orient_u = self.sample.orient_u
		orient_v = self.sample.orient_v 
		output_file.write('#Orient      '+str(orient_u[0])+' '+str(orient_u[1])+' '+str(orient_u[2])+' '+str(orient_v[0])+' '+str(orient_v[1])+' '+str(orient_v[2])+'\n')
		output_file.write('#MonoSpacing 3.35416\n')
		output_file.write('#AnaSpacing  3.35416\n')
		output_file.write('#UBEnabled   0\n')
		output_file.write('#Fixed       All devices are free\n')
		output_file.write('#Columns             QX            QY            QZ             E            A4          Time       Monitor            A2            A3            A5            A6           DFM            A1       AColMon AnalyzerTheta01 AnalyzerTheta02 AnalyzerTheta03 AnalyzerTheta04 AnalyzerTheta05 AnalyzerTheta06 AnalyzerTheta07 AnalyzerTheta08 AnalyzerTheta09 AnalyzerTheta10 AnalyzerTheta11 AnalyzerTheta12 AnalyzerTheta13 AnalyzerTheta14 AnalyzerTheta15 AnalyzerTheta16 AnalyzerTheta17 AnalyzerTheta18 AnalyzerTheta19 AnalyzerTheta20       BColMon BaseSampleTheta      BeFilMon         Beta1         Beta2        DFMDTS          DIFF        DIFF01        DIFF02        DIFF03        DIFF04        DIFF05        DIFF06        DIFF07        DIFF08        DIFF09        DIFF10        DIFF11        DIFF12        DIFF13        DIFF14        DIFF15        DIFF16        DIFF17        DIFF18        DIFF19        DIFF20          DMBT            Ef            Ei          FLIP         Focus             H           HKL             K        Kidney             L      MBTSlide          MCFX      MgFilMon    MonBlade01    MonBlade02    MonBlade03    MonBlade04    MonBlade05    MonBlade06    MonBlade07    MonBlade08    MonBlade09    MonBlade10    MonBlade11    MonBlade12    MonBlade13    MonBlade14    MonBlade15    MonBlade16    MonBlade17    MonBlade18    MonBlade19    MonBlade20    MonBlade21        MonRot      MonTrans          PTAI      PgFilMon         SPARE          SPEC        SPEC01        SPEC02        SPEC03        SPEC04        SPEC05        SPEC06        SPEC07        SPEC08        SPEC09        SPEC10        SPEC11        SPEC12        SPEC13        SPEC14        SPEC15        SPEC16        SPEC17        SPEC18        SPEC19        SPEC20     SmplLTilt     SmplUTilt         SmplX         SmplY         SmplZ          VBAH          VBAV         cfxbe       cfxhopg        cfxmgf    timestamp\n')
		output_file.close()

	def getIntensity(self,datfile):
		#Gets the Intensity total for both diff and spec files
		try:
			npArray = np.genfromtxt(datfile)
			Intensity = npArray[0:5]
			Ierr = npArray[5:10]
			N = npArray[10:15]
			#Note that we only care about intensity, as the MC simulation counts aren't meaningful
			TotIntensity = np.nansum(Intensity)
			TotErr = np.sqrt(np.sum(Ierr**2))
			try:
				float(TotIntensity)
				float(TotErr)
			except ValueError:
				TotIntensity=0
				TotErr=0
		except Exception as e:
			TotIntensity=0
			TotErr=0
		return TotIntensity,TotErr

	def getParams(self,fname):
		#Extracts parameters provided at top of mcstas .dat file
		#Builds a dictionary of relevant params at top of the file
		#Note that non-param entries at top of file are nonsense in the dict 
		file=open(fname)
		file.seek(0)
		s = file.readline()
		if s=='# Format: McCode with text headers\n':
			a = s.split("=")
			b = s.split(':')
			dict = {}
			while b[0]!= '# statistics':
				check1 = type(a)==list 
				check2 = len(a)>1
				if check1*check2==1:
					dict[a[0]]=a[1][0:-1]
				else:
					x=1
				s= file.readline()
				a = s.split('=')
				b = s.split(':')
			file.close()
			return dict
		else:
			#This is for the weird case of just zeros instead of entries 
			#Happens for a few diff_detector files, not sure why
			print('File containing only 0s found')
			dict = {}
			dict['# Param: A3_angle']=0
			dict['# Param: kidney_angle']=0
			dict['# Param: beta_1']=0
			dict['# Param: beta_2']=0
			return dict 



	def load_data_matrix_from_csv(self,csv_file=False):
		"""Provided a csv_file produced by a previous data matrix, loads it and appends it to the current data_matrix.
			Duplicates are automatically removed. 

		"""
		if csv_file==False:
			#use default
			csv_name=self.csv_name
		else:
			csv_name= csv_file
		#Check if the file exits:
		if not os.path.isfile(self.kidney_result_dir+self.exptName+csv_name):
			print('WARNING: Cannot generate data matrix. File '+str(self.kidney_result_dir+self.exptName+csv_name)+' not found.')
		else:
			self.data_matrix=False
			df = pd.read_csv(self.kidney_result_dir+self.exptName+csv_name,header=0)
			#drop the duplicates
			df=df.drop_duplicates(subset=['A3','Ei','Ef','Kidney'],keep='last')
			df.index=range(len(df.index))
			self.data_matrix=df
		return 1

	def combine_all_csv(self,fname='_total.csv'):
		"""Combines all of the .csv files in the result directory and saves into a composite large one. This can be slow. 
			Preserves old files. 

		:param fname: Suffix to append output csv filename with. Total filename is (result_dir + exptName + fname).
		:type fnaem: str

		"""
		all_csvs = glob.glob(self.kidney_result_dir+'*.csv')
		df = pd.concat(map(lambda file: pd.read_csv(file,header=0),all_csvs))
		df=df.drop_duplicates(subset=['A3','Ei','Ef','Kidney'],keep='last')
		self.data_matrix=df 
		#Save into a cumulative file
		if os.path.exists(self.kidney_result_dir+self.exptName+fname):
			print('WARNING: Overwriting previous total file '+self.exptName+str(fname))
		df.to_csv(self.kidney_result_dir+self.exptName+fname,header=True)
		return 1

	def append_data_matrix_from_csv(self,csv_file=False):
		"""Loads a csv_file containing a data matrix and appends it to the data matrix.

			:param csv_file: Filename of data matrix stored in .csv file.
			:type csv_file: str
		"""
		orig_frame = self.data_matrix
		new_frame = pd.read_csv(self.kidney_result_dir+csv_file,header=0)
		frames = [orig_frame,new_frame]
		final_frame = pd.concat(frames)
		final_frame=final_frame.drop_duplicates(subset=['A3','Ei','Ef','Kidney'],keep='last')
		self.data_matrix=final_frame
		return 1

	def scan_to_csv(self,simulation_folder,file_suffix='',PTAI_det=False):
		#Given one folder containing a simulation for a particular configuration, appends the folder to the overall data matrix. 
		col_labels=['A3','A2','A5','A6','H','K','L','Ei','Ef','DIFF','DIFF1','DIFF2','DIFF3','DIFF4','DIFF5','DIFF6','DIFF7','DIFF8','DIFF9','DIFF10','DIFF11',\
					'DIFF12','DIFF13','DIFF14','DIFF15','DIFF16','DIFF17','DIFF18','DIFF19','DIFF20','SPEC','SPEC1','SPEC2','SPEC3','SPEC4','SPEC5','SPEC6','SPEC7','SPEC8','SPEC9','SPEC10','SPEC11',\
					'SPEC12','SPEC13','SPEC14','SPEC15','SPEC16','SPEC17','SPEC18','SPEC19','SPEC20','Kidney','A4','Monitor','Time','AnalyzerTheta01','AnalyzerTheta02','AnalyzerTheta03','AnalyzerTheta04',\
					'AnalyzerTheta05','AnalyzerTheta06','AnalyzerTheta07','AnalyzerTheta08','AnalyzerTheta09','AnalyzerTheta10','AnalyzerTheta11','AnalyzerTheta12','AnalyzerTheta13','AnalyzerTheta14','AnalyzerTheta15',\
					'AnalyzerTheta16','AnalyzerTheta17','AnalyzerTheta18','AnalyzerTheta19','AnalyzerTheta20','PTAI',\
					'DIFF1Err','DIFF2Err','DIFF3Err','DIFF4Err','DIFF5Err','DIFF6Err','DIFF7Err','DIFF8Err','DIFF9Err','DIFF10Err','DIFF11Err',\
					'DIFF12Err','DIFF13Err','DIFF14Err','DIFF15Err','DIFF16Err','DIFF17Err','DIFF18Err','DIFF19Err','DIFF20Err',\
					'SPEC1Err','SPEC2Err','SPEC3Err',\
					'SPEC4Err','SPEC5Err','SPEC6Err','SPEC7Err','SPEC8Err','SPEC9Err','SPEC10Err','SPEC11Err',\
					'SPEC12Err','SPEC13Err','SPEC14Err','SPEC15Err','SPEC16Err','SPEC17Err','SPEC18Err','SPEC19Err','SPEC20Err']
		#Also need to add errors to both SPEC and DIFF

		data_matrix = pd.DataFrame(index=[0],columns=col_labels)
		diffiles=[]
		specfiles=[]
		for det_ind in np.arange(0,20,1):
			diffiles.append(simulation_folder+'/diff_detector_'+str(det_ind)+'.dat')
			specfiles.append(simulation_folder+'/spec_detector_'+str(det_ind)+'.dat')
		index=0
		if PTAI_det is False:
			PTAI_det = self.PTAI_det
		if len(diffiles)==20:
			#Iterate through detectors 1-20
			diff_arr = np.zeros(20)
			spec_arr = np.zeros(20)
			diff_err_arr = np.zeros(20)
			spec_err_arr = np.zeros(20)
			for det_i in range(len(diff_arr)):
				I_diff,Err_diff = self.getIntensity(diffiles[det_i])
				I_spec,Err_spec =self.getIntensity(specfiles[det_i])
				diff_arr[det_i]=I_diff 
				spec_arr[det_i]=I_spec
				diff_err_arr[det_i]=Err_diff
				spec_err_arr[det_i]=Err_spec 
			params = self.getParams(diffiles[0])
			PTAI_ind = PTAI_det-1
			data_matrix.loc[index,'DIFF']=diff_arr[PTAI_ind]
			data_matrix.loc[index,'SPEC']=spec_arr[PTAI_ind]
			for i in np.arange(1,21,1):
				data_matrix.loc[index,'DIFF'+str(i)]=diff_arr[i-1]
				data_matrix.loc[index,'SPEC'+str(i)]=spec_arr[i-1]
				data_matrix.loc[index,'DIFF'+str(i)+'Err']=diff_err_arr[i-1]
				data_matrix.loc[index,'SPEC'+str(i)+'Err']=spec_err_arr[i-1]
			#Intensities successfully extracted. 
			data_matrix.loc[index,'PTAI']=PTAI_det
			#The rest of the params require the information in the header
			A3_param = float(params['# Param: A3_angle'])
			Ei_param = float(params['# Param: EM'])
			Ef_param = float(params['# Param: EF_all'])
			kidney_param = float(params['# Param: kidney_angle'])
			data_matrix.loc[index,'A3']=A3_param
			data_matrix.loc[index,'Ei']=Ei_param 
			data_matrix.loc[index,'Ef']=Ef_param
			data_matrix.loc[index,'Kidney']=kidney_param
			#Leaving H, K, L, alone for now. 
			data_matrix.loc[index,'H']='N/A'
			data_matrix.loc[index,'K']='N/A'
			data_matrix.loc[index,'L']='N/A'
			#Need to calculate A2, monochromator reflection is 002.
			neutron_lami = 9.045/np.sqrt(Ei_param)
			neutron_lamf = 9.045/np.sqrt(Ef_param)
			Q_002 = 1.873 #For pyrolitic graphite
			twoThetai = 2.0*np.arcsin(Q_002*neutron_lami/(4.0*np.pi))*180.0/np.pi
			twoThetaf = 2.0*np.arcsin(Q_002*neutron_lamf/(4.0*np.pi))*180.0/np.pi
			data_matrix.loc[index,'A2']=twoThetai
			data_matrix.loc[index,'A4']=kidney_param-60.0 #Might be off but Mslice doesn't use this anyway.
			data_matrix.loc[index,'A6']=twoThetaf
			data_matrix.loc[index,'A5']=twoThetaf/2.0
			data_matrix.loc[index,'Monitor']=1.0
			#Individual analyzers will be assume to be the same as A5
			for i in np.arange(1,21,1):
				colstr = '{num:02d}'.format(num=i)
				data_matrix.loc[index,'AnalyzerTheta'+colstr]=twoThetaf/2.0
			data_matrix.loc[index,'Time']=1.0
		#Need to make a unique name based on the scan. 
		scan_prefix='_Ei_'+'{:.3f}'.format(Ei_param)+'_Ef_'+'{:.3f}'.format(Ef_param)+'_A3_'+'{:.4f}'.format(A3_param)+'_kidney_'+'{:.4f}'.format(kidney_param)
		#Save the matrix, or append to old file if it exists.
		if not os.path.isfile(self.kidney_result_dir+self.exptName+scan_prefix+self.csv_name):
			data_matrix.to_csv(self.kidney_result_dir+self.exptName+scan_prefix+file_suffix+self.csv_name,header=True)
		else:
			data_matrix.to_csv(self.kidney_result_dir+self.exptName+scan_prefix+file_suffix+self.csv_name,mode='a',header=False)
		csvname = self.exptName+scan_prefix+file_suffix+self.csv_name
		return csvname

	def combine_csv_scans(self,preserve_old=False,flagstr=False):
		"""Takes individual csvs which are the output of each scan and combines them into a master csv. 
			Also updates the data matrix to reflect this."""
		all_files = glob.glob(self.kidney_result_dir+'*.csv')

		flist = []
		for fname in all_files:
			if flagstr==False:
				suffix='_combined_'
				df = pd.read_csv(fname,header=0,index_col=0)
				flist.append(df)
			else:
				suffix=flagstr
				if flagstr in fname:
					df =pd.read_csv(fname,header=0,index_col=0)
					flist.append(df)
		data_matrix=pd.concat(flist,axis=0,ignore_index=True)
		#delete all of the previous files
		if preserve_old==False and flagstr==False:
			num_csv = len(glob.glob(self.kidney_result_dir+'*.csv'))
			while num_csv>0:
				try:
					os.system('rm -rf '+str(self.kidney_result_dir+'*.csv'))
				except Exception as e:
					print('Warning: \n'+str(e))
					time.sleep(0.01)
				num_csv = len(glob.glob(self.kidney_result_dir+'*.csv'))
		if preserve_old==False and type(flagstr)!=bool:
			num_csv = len(glob.glob(self.kidney_result_dir+'*'+flagstr+'*.csv'))
			while num_csv>0:
				try:
					os.system('rm -rf '+str(self.kidney_result_dir+'*'+flagstr+'*.csv'))
				except Exception as e:
					print('Warning: \n'+str(e))
					time.sleep(0.01)
				num_csv = len(glob.glob(self.kidney_result_dir+os.path.join(self.kidney_result_dir+'*'+flagstr+'*.csv')))
		#Save the data matrix at this point after removing duplicate rows.
		data_matrix = data_matrix.drop_duplicates(subset=['A3','Ei','Ef','Kidney'],keep='last')
		#In the case of specific names, data file should just be overwritten if it already exists.
		outfilename = suffix+self.csv_name
		data_matrix.to_csv(self.kidney_result_dir+self.exptName+outfilename,header=True)
		return outfilename

	def project_data_QE(self,which_data='mcstas',PTAI=False):
		"""Project the results stored in the data matrix into QE space- requires information from the sample object
		
		:param which_data: Determines if experimental or simulated data should be used, 
			'mcstas' to use calculated scattering and 'macs' for experimental. Allowed value 'mcstas' and 'macs'
		:type which_data: str
		"""
		if which_data=='mcstas':
			data_mat = self.data_matrix
		elif which_data=='macs':
			data_mat = self.expt_data_matrix
		else:
			data_mat = self.data_matrix
		orient_u=self.sample.orient_u
		orient_v=self.sample.orient_v
		num_configs = len(data_mat.index)
		data_indices = np.arange(0,num_configs*20,1)
		col_labels = ['H','K','L','Qu','Qv','|Q|','Qx','Qz','Ei','DeltaE','DIFF','DIFFErr','SPEC','SPECErr','PTAI','Err','Det_index']
		proj_mat = pd.DataFrame(index=data_indices,columns=col_labels)
		out_mat = np.zeros((np.shape(data_indices)[0],len(col_labels)))
		A3_array = np.array(data_mat['A3'].tolist())
		Ei_array = np.array(data_mat['Ei'].tolist())
		Ef_array = np.array(data_mat['Ef'].tolist())

		kid_array = np.array(data_mat['Kidney'].tolist())
		spec_label_list = ['SPEC1','SPEC2','SPEC3','SPEC4','SPEC5','SPEC6','SPEC7','SPEC8','SPEC9','SPEC10','SPEC11',\
		                  'SPEC12','SPEC13','SPEC14','SPEC15','SPEC16','SPEC17','SPEC18','SPEC19','SPEC20']
		diff_label_list = ['DIFF1','DIFF2','DIFF3','DIFF4','DIFF5','DIFF6','DIFF7','DIFF8','DIFF9','DIFF10','DIFF11',\
		                  'DIFF12','DIFF13','DIFF14','DIFF15','DIFF16','DIFF17','DIFF18','DIFF19','DIFF20']
		spec_err_label_list = ['SPEC1Err','SPEC2Err','SPEC3Err','SPEC4Err','SPEC5Err','SPEC6Err','SPEC7Err',\
								'SPEC8Err','SPEC9Err','SPEC10Err','SPEC11Err',\
		                  'SPEC12Err','SPEC13Err','SPEC14Err','SPEC15Err','SPEC16Err','SPEC17Err','SPEC18Err',\
		                  'SPEC19Err','SPEC20Err']
		diff_err_label_list = ['DIFF1Err','DIFF2Err','DIFF3Err','DIFF4Err','DIFF5Err','DIFF6Err','DIFF7Err',\
						'DIFF8Err','DIFF9Err','DIFF10Err','DIFF11Err',\
		                  'DIFF12Err','DIFF13Err','DIFF14Err','DIFF15Err','DIFF16Err','DIFF17Err','DIFF18Err',\
		                  'DIFF19Err','DIFF20Err']

		spec_array = data_mat[spec_label_list].to_numpy().astype(float)
		diff_array = data_mat[diff_label_list].to_numpy().astype(float)
		ptai_array = data_mat['PTAI'].to_numpy()

		#Error depends on type of matrix being projected
		if which_data=='macs':
			monitor_array = data_mat['Monitor'].to_numpy()
			spec_err_array = np.sqrt(spec_array)
			spec_array/=monitor_array[:,None]
			spec_err_array/=monitor_array[:,None]
			diff_err_array = np.sqrt(diff_array)
			diff_array/=monitor_array[:,None]
			diff_err_array /=monitor_array[:,None]
		else:
			diff_err_array=data_mat[diff_err_label_list].to_numpy()
			spec_err_array=data_mat[spec_err_label_list].to_numpy()
			diff_err_array[diff_array==0]=np.inf 
			spec_err_array[spec_array==0]=np.inf
			#Have found it is best to just assume sqrt errors...
			diff_err_array=np.ones(np.shape(diff_err_array))
			spec_err_array=np.ones(np.shape(spec_err_array))


		det_index_list = np.arange(1,21,1) #List of detector indices
		det_angle_list_k0 = -76.0+(det_index_list-1.0)*8.0 #Detector angles if kidney=0

		#Generate a matrix of detector angles for every pointin the matrix of intensities. 
		# Incoming intensity matrix is an Nx20 matrix where each row is a configuration and each column is a detector
		det_angle_mat = np.zeros((num_configs,20))

		A3_mat = np.zeros((num_configs,20)) #Also need to keep track of the sample rotation at each point
		A3_mat += A3_array[:,None]
		Ei_mat = np.zeros((num_configs,20))
		Ei_mat += Ei_array[:,None]
		Ef_mat = np.zeros((num_configs,20))
		Ef_mat += Ef_array[:,None]
		PTAI_mat = np.zeros((num_configs,20))
		PTAI_mat += ptai_array[:,None]
		det_index_mat = np.zeros((num_configs,20))
		det_index_mat+=det_index_list

		det_angle_mat += det_angle_list_k0 #Assumes kidney=0 for all rows, fix now
		det_angle_mat += kid_array[:,None] # Take the beam direction to be horizontal
		#All points now have an assosciated angle. Reshape both the angle matrix and the intensity matrix
		# to be of the shape of the output matrix
		det_angle_list = np.reshape(det_angle_mat,(np.shape(out_mat)[0],1))
		det_index_list = np.reshape(det_index_mat,(np.shape(out_mat)[0],1))
		spec_out_list = np.reshape(spec_array,(np.shape(out_mat)[0],1))[:,0]
		diff_out_list = np.reshape(diff_array,(np.shape(out_mat)[0],1))[:,0]
		diff_out_err_list= np.reshape(diff_err_array,(np.shape(out_mat)[0],1))[:,0]
		spec_out_err_list = np.reshape(spec_err_array,(np.shape(out_mat)[0],1))[:,0]
		A3_out_list = np.reshape(A3_mat,(np.shape(out_mat)[0],1))
		Ei_out_list = np.reshape(Ei_mat,(np.shape(out_mat)[0],1))
		Ef_out_list = np.reshape(Ef_mat,(np.shape(out_mat)[0],1))
		ptai_out_list = np.reshape(PTAI_mat,(np.shape(out_mat)[0],1))
		DeltaE_list = Ei_out_list - Ef_out_list
		#Remembering that the sample u-vector is perpendicular to the beam, we now project the detector angles onto the 
		# sample alignment

		udir_list = np.zeros((len(det_angle_list),2)) # direction in x-z plane
		vdir_list = np.zeros((len(det_angle_list),2))
		udir_list[:,1]+=1
		vdir_list[:,0]+=1 

		#Rotate every row by its respective A3
		A3_out_list_rad= A3_out_list*np.pi/180.0
		R = np.array([[np.cos(A3_out_list_rad),-np.sin(A3_out_list_rad)],\
		              [np.sin(A3_out_list_rad),np.cos(A3_out_list_rad)]])
		R = R[:,:,:,0] #Remove extra dim at the end
		for i in range(len(spec_out_list)):
		    u_dir_0 = udir_list[i,:]
		    v_dir_0 = vdir_list[i,:]
		    R_mat = R[:,:,i]
		    u_dir_rot = np.matmul(R_mat,u_dir_0)
		    v_dir_rot = np.matmul(R_mat,v_dir_0)
		    udir_list[i,:]=u_dir_rot
		    vdir_list[i,:]=v_dir_rot
		#Crystal axes are now properly rotated- get the projection of each detector onto the vector
		xdet_list = np.cos(det_angle_list*np.pi/180.0)
		ydet_list = np.sin(det_angle_list*np.pi/180.0)
		det_dir_mat = np.zeros((len(spec_out_list),2))
		det_dir_mat[:,0]=xdet_list[:,0]
		det_dir_mat[:,1]=ydet_list[:,0]

		#Get the total Q for each scattering event based on twotheta and energy
		lami_out_list = 9.045/np.sqrt(Ei_out_list)
		lamf_out_list = 9.045/np.sqrt(Ef_out_list)
		ki_dir_list = np.ones((len(spec_out_list),2))
		ki_dir_list[:,1]=0 #Define x-direction as beam direction
		ki_mag_list = 2.0*np.pi/lami_out_list
		ki_vec_list=ki_mag_list*ki_dir_list
		kf_mag_list = 2.0*np.pi/lamf_out_list
		kf_vec_list = np.copy(det_dir_mat)
		kf_vec_list[:,0]*=kf_mag_list[:,0]
		kf_vec_list[:,1]*=kf_mag_list[:,0]
		Q_vec_list = ki_vec_list-kf_vec_list

		#Recalling Q^2 = ki^2 + kf^2 - 2kikfcos2theta, need to get 2theta from ki kf directions first
		num = ki_vec_list[:,0]*kf_vec_list[:,0]+ki_vec_list[:,1]*kf_vec_list[:,1]
		denom = ki_mag_list*kf_mag_list
		denom=denom[:,0]
		value = num/denom.T
		value=value.T
		twoTheta_list = np.arccos(value)
		Q_list = np.sqrt(ki_mag_list[:,0]**2 + kf_mag_list[:,0]**2 - 2.0*ki_mag_list[:,0]*kf_mag_list[:,0]*np.cos(twoTheta_list))

		Q_dir_list = Q_vec_list / Q_list[:,None]
		Qu_proj_dir_list = udir_list[:,0]*Q_dir_list[:,0]+udir_list[:,1]*Q_dir_list[:,1]
		Qv_proj_dir_list = vdir_list[:,0]*Q_dir_list[:,0]+vdir_list[:,1]*Q_dir_list[:,1]#Now have directions of Q and U.

		#This can go in the output matrix now. 
		proj_mat['|Q|']=Q_list
		u_vec_mag=self.sample.Qmag_HKL(self.sample.orient_u[0],self.sample.orient_u[1],self.sample.orient_u[2])
		v_vec_mag=self.sample.Qmag_HKL(self.sample.orient_v[0],self.sample.orient_v[1],self.sample.orient_v[2])
		#The projection of kf onto each direction gives the scattering plane
		U_proj = -1.0*Qu_proj_dir_list*Q_list/u_vec_mag
		V_proj = -1.0*Qv_proj_dir_list*Q_list/v_vec_mag #For some reason a minus sign is required here...



		#Get the HKL values from this
		HKL_list = np.outer(U_proj,orient_u) + np.outer(V_proj,orient_v)
		H_list = HKL_list[:,0]*-1.0
		K_list = HKL_list[:,1]*-1.0
		L_list = HKL_list[:,2]*-1.0

		proj_mat['Det_index']=det_index_list
		#Save to the projected matrix. 
		proj_mat['Qu']=U_proj
		proj_mat['Qv']=V_proj
		proj_mat['SPEC']=spec_out_list
		proj_mat['DIFF']=diff_out_list
		proj_mat['SPECErr']=spec_out_err_list
		proj_mat['DIFFErr']=diff_out_err_list
		proj_mat['Qx']=Q_vec_list[:,0]
		proj_mat['Qz']=Q_vec_list[:,1]
		proj_mat['H']=H_list
		proj_mat['K']=K_list
		proj_mat['L']=L_list
		proj_mat['Ei']=Ei_out_list
		proj_mat['DeltaE']=DeltaE_list
		proj_mat['PTAI']=ptai_out_list
		if PTAI==True:
			proj_mat=proj_mat[proj_mat['Det_index']==proj_mat['PTAI']]
		if which_data=='mcstas':
			self.projected_matrix=proj_mat
		elif which_data=='macs':
			self.projected_expt_matrix = proj_mat 
		else:
			self.projected_matrix=proj_mat
		return 1 

	def bin_constE_slice(self,num_ubins,num_vbins,urange,vrange,omega_range,which_data='mcstas'):
		"""If the data matrix has already been projection into Q-space, returns a constant energy slice based on the specified bins.
		The directions are specified by the crystal orientation, i.e. the u-v vectors. 

		:param num_ubins: Number of bins along the u-direction. 
		:type num_ubins: int
		:param num_vbins: number of bins along the v-direction.
		:type num_vbins: int
		:param urange: List of min and max values along u-axis in format of [umin, umax]
		:type urange: list
		:param vrange: list of min and max values along v-axis in format of [vmin, vmax]
		:type vrange: list
		:param omega_range: List of min and max values in energy transfer to average over in format of [Emin, Emax]
		:type omega_range: [float, float]
		:param which_data: Determines if experimental or simulated data should be used, 
			'mcstas' to use calculated scattering and 'macs' for experimental. Allowed value 'mcstas' and 'macs'
		:type which_data: str
		:return X,Y,Z: Matrices of U-coordinates, V-coordinates, and intensities. Suitable to plot in plt.pcolormesh.
		:rtype: np.ndarray,np.ndarray,np.ndarray
		"""
		if type(self.projected_matrix)==bool and which_data=='mcstas':
			self.project_data_QE()
		if type(self.projected_expt_matrix)==bool and which_data=='macs':
			self.project_data_QE(which_data='macs')
		#Filter out all points that do not fall in the energy and Q range.
		if which_data=='mcstas':
			df_copy = self.projected_matrix.copy()
		elif which_data=='macs':
			df_copy=self.projected_expt_matrix.copy()
		else:
			df_copy = self.projected_matrix.copy()
		df_copy=df_copy.loc[(df_copy['DeltaE']<=omega_range[1]) & (df_copy['DeltaE']>=omega_range[0])]
		df_copy=df_copy.loc[(df_copy['Qu']>=urange[0]) & (df_copy['Qu']<=urange[1])]
		df_copy=df_copy.loc[(df_copy['Qv']>=vrange[0]) & (df_copy['Qv']<=vrange[1])]

		ret = scipy.stats.binned_statistic_2d(x=df_copy['Qu'],y=df_copy['Qv'],values=df_copy['SPEC'],statistic='mean',\
			bins=[num_ubins,num_vbins])
		X,Y=np.meshgrid(ret.x_edge,ret.y_edge)
		Z=ret.statistic
		return X,Y,Z

	def take_slice(self,ubins,vbins,omegabins,which_data='mcstas',statistic='mean',smooth=False):
		"""
		Takes a slice integrating over one dimension in Q-space. Two  of the bins must be in MANTID/HORACE style
		format [min,max,number of bins], and one must be integrated over and specified as [min,max]

		:param ubins: Bin specification in mantid format along u-direction (min,max,number of bins)
		:type ubins: list
		:param vbins: Bin specification in mantid format along v-direction (min,max,number of bins)
		:type vbins: list
		:param omeagabins: Bin specification in mantid format along energy axis (min,max,number of bins)
		:type omegabins: list
		:param which_data: Determines if experimental or simulated data should be used, 
			'mcstas' to use calculated scattering and 'macs' for experimental. Allowed value 'mcstas' and 'macs'
		:type which_data: str
		:param statistic: Todo - not currently supported, always 'mean'
		:type statistic: str
		:param smooth: Output slice gaussian smoothing, either false or std dev in pixels.
		:type param: bool or int
		:return X,Y,Z: Matrices of U-coordinates, V-coordinates, and intensities. Suitable to plot in plt.pcolormesh. 
			The X and Y matrices are bin edges, not centers. 
		:rtype: np.ndarray,np.ndarray,np.ndarray
		"""

		if type(self.projected_matrix)==bool and which_data=='mcstas':
			self.project_data_QE()
		if type(self.projected_expt_matrix)==bool and which_data=='macs':
			self.project_data_QE(which_data='macs')
		tot_binlength = len(ubins)+len(vbins)+len(omegabins)
		if tot_binlength!=8 or (len(ubins) not in [2,3]) or (len(vbins) not in [2,3]) or (len(omegabins) not in [2,3]):
			print('Cut specification invalid. Two dimensions must be in the form of [min,max], and the cut axis\n \
					should be in format of [min, max, numbins].')
			return 0,0,0
		if len(ubins)==2:
			bin_axis='Qu'
			slice_axis1 = 'Qv'
			slice_axis2 = 'DeltaE'
			bin_limit = ubins 
			slice_limit1 = vbins
			slice_limit2 = omegabins 
			bin_list = np.array([\
				np.linspace(slice_limit1[0],slice_limit1[1],slice_limit1[2]),\
				np.linspace(slice_limit2[0],slice_limit2[1],slice_limit2[2]),\
				bin_limit],dtype=object)
			bindim_index = 2
			slicedim_index1=0
			slicedim_index2=1
		elif len(vbins)==2:
			bin_axis='Qv'
			slice_axis1='Qu'
			slice_axis2='DeltaE'
			bin_limit=vbins 
			slice_limit1=ubins 
			slice_limit2=omegabins 
			bin_list = np.array([np.linspace(slice_limit1[0],slice_limit1[1],slice_limit1[2]),\
				np.linspace(slice_limit2[0],slice_limit2[1],slice_limit2[2]),\
				bin_limit],dtype=object)
			bindim_index=2
			slicedim_index1=0
			slicedim_index2=1
		elif len(omegabins)==2:
			bin_axis='DeltaE'
			slice_axis1='Qu'
			slice_axis2='Qv'
			bin_limit=omegabins
			slice_limit1=ubins 
			slice_limit2=vbins 
			bin_list = np.array([np.linspace(slice_limit1[0],slice_limit1[1],slice_limit1[2]),\
				np.linspace(slice_limit2[0],slice_limit2[1],slice_limit2[2]),\
				bin_limit],dtype=object)
			slicedim_index1=0
			slicedim_index2=1
			bindim_index=2
		else:
			print('Cut specification invalid')
			return 0,0,0
		if which_data=='mcstas':
			df_copy = self.projected_matrix.copy()
		elif which_data=='macs':
			df_copy = self.projected_expt_matrix.copy()
		else:
			df_copy = self.projected_matrix.copy()
		df_copy = df_copy.loc[(df_copy[bin_axis]<=bin_limit[1]) & (df_copy[bin_axis]>=bin_limit[0])]
		df_copy = df_copy.loc[(df_copy[slice_axis1]<=slice_limit1[1]) & (df_copy[slice_axis1]>=slice_limit1[0])]
		df_copy = df_copy.loc[(df_copy[slice_axis2]<=slice_limit2[1]) & (df_copy[slice_axis2]>=slice_limit2[0])]
		#Data now restricted to the relevant region of Q-E space. Now bin:
		sampledat = np.array([df_copy[slice_axis1].to_numpy(),df_copy[slice_axis2].to_numpy(),df_copy[bin_axis].to_numpy()]).T
		values = df_copy['SPEC'].to_numpy().T
		errs = df_copy['SPECErr'].to_numpy().T 
		errs[errs==0]=np.nan
		weights = 1.0/errs 
		weights[np.isinf(weights)]=np.nan
		weighted_vals = values*weights
		weighted_vals[np.isnan(weighted_vals)]=0.0
		sumofweights =  np.nansum(weights)
		def weighted_mean(weighted_vals):
			weighted_vals[np.isnan(weighted_vals)]=0 
			weighted_vals[np.isinf(weighted_vals)]=0 
			good_i = np.intersect1d(np.where(weighted_vals!=0)[0],np.where(~np.isnan(weighted_vals))[0])
			weighted_vals=weighted_vals[good_i]
			num = np.sqrt(np.nansum(weighted_vals))
			return num
		def weighted_mean_errs(weights):
			weights[weights==0]=np.nan 
			errs=1.0/weights 
			errs[errs==0]=np.nan
			return np.sqrt(np.nansum(errs**2))/np.nansum(weights)
		#Rather than simply computing the mean, we need to compute the weighted mean and its error bar. 
		ret_weightvals = scipy.stats.binned_statistic_dd(sample=sampledat,values=values,statistic=weighted_mean,bins=bin_list)
		sumweights = scipy.stats.binned_statistic_dd(sample=sampledat,values=weights,statistic='sum',bins=bin_list)
		ret_errs = scipy.stats.binned_statistic_dd(sample=sampledat,values=weights,statistic=weighted_mean_errs,bins=bin_list)
		x = ret_weightvals.bin_edges[slicedim_index1]
		y = ret_weightvals.bin_edges[slicedim_index2]
		X,Y = np.meshgrid(x,y)
		Z = ret_weightvals.statistic[:,:,0]/sumweights.statistic[:,:,0]
		Err = ret_errs.statistic[:,:,0]
		if type(smooth)!=bool:
			#Smooth intensities, errors.
			old_nani = [np.isnan(Z)]
			Z[np.isnan(Z)]=0
			Err[np.isnan(Err)]=0
			Z = scipy.ndimage.gaussian_filter(Z,sigma=smooth)
			Err = scipy.ndimage.gaussian_filter(Err,sigma=smooth)
			Z[tuple(old_nani)]=np.nan 
			Err[tuple(old_nani)]=np.nan
		return X,Y,Z,Err

	def take_volume(self,ubins,vbins,omegabins,which_data='mcstas',statistic='mean',smooth=False):
		"""
		Returns a volume integrating over no dimensions. All bins must be in MANTID/HORACE style
		format [min,max,number of bins]

		:param ubins: Bin specification in mantid format along u-direction (min,max,number of bins)
		:type ubins: list
		:param vbins: Bin specification in mantid format along v-direction (min,max,number of bins)
		:type vbins: list
		:param omeagabins: Bin specification in mantid format along energy axis (min,max,number of bins)
		:type omegabins: list
		:param which_data: Determines if experimental or simulated data should be used, 
			'mcstas' to use calculated scattering and 'macs' for experimental. Allowed value 'mcstas' and 'macs'
		:type which_data: str
		:param statistic: Todo - not currently supported, always 'mean'
		:type statistic: str
		:param smooth: Output slice gaussian smoothing, either false or std dev in pixels.
		:type param: bool or int
		:return X,Y,Z: Matrices of U-coordinates, V-coordinates, and intensities. Suitable to plot in plt.pcolormesh. 
			The X and Y matrices are bin edges, not centers. 
		:rtype: np.ndarray,np.ndarray,np.ndarray
		"""

		if type(self.projected_matrix)==bool and which_data=='mcstas':
			self.project_data_QE()
		if type(self.projected_expt_matrix)==bool and which_data=='macs':
			self.project_data_QE(which_data='macs')
		tot_binlength = len(ubins)+len(vbins)+len(omegabins)
		if tot_binlength!=9 or (len(ubins) not in [3]) or (len(vbins) not in [3]) or (len(omegabins) not in [3]):
			print('Volume specification invalid. All dimensions must be in the form of [min, max, numbins].')
			return 0,0,0,0
		if which_data=='mcstas':
			df_copy = self.projected_matrix.copy()
		elif which_data=='macs':
			df_copy = self.projected_expt_matrix.copy()
		else:
			df_copy = self.projected_matrix.copy()
		df_copy = df_copy.loc[(df_copy['Qu']<=ubins[1]) & (df_copy['Qu']>=ubins[0])]
		df_copy = df_copy.loc[(df_copy['Qv']<=vbins[1]) & (df_copy['Qv']>=vbins[0])]
		df_copy = df_copy.loc[(df_copy['DeltaE']<=omegabins[1]) & (df_copy['DeltaE']>=omegabins[0])]
		#Data now restricted to the relevant region of Q-E space. Now bin:
		sampledat = np.array([df_copy['Qu'].to_numpy(),df_copy['Qv'].to_numpy(),df_copy['DeltaE'].to_numpy()]).T
		values = df_copy['SPEC'].to_numpy().T
		errs = df_copy['SPECErr'].to_numpy().T 
		errs[errs==0]=np.nan
		weights = 1.0/errs 
		weights[np.isinf(weights)]=np.nan
		weighted_vals = values*weights
		weighted_vals[np.isnan(weighted_vals)]=0.0
		sumofweights =  np.nansum(weights)
		def weighted_mean(weighted_vals):
			weighted_vals[np.isnan(weighted_vals)]=0 
			weighted_vals[np.isinf(weighted_vals)]=0 
			good_i = np.intersect1d(np.where(weighted_vals!=0)[0],np.where(~np.isnan(weighted_vals))[0])
			weighted_vals=weighted_vals[good_i]
			num = np.sqrt(np.nansum(weighted_vals))
			return num
		def weighted_mean_errs(weights):
			weights[weights==0]=np.nan 
			errs=1.0/weights 
			errs[errs==0]=np.nan
			return np.sqrt(np.nansum(errs**2))/np.nansum(weights)
		#Rather than simply computing the mean, we need to compute the weighted mean and its error bar. 
		bin_list = np.array([np.linspace(ubins[0],ubins[1],ubins[2]),\
							np.linspace(vbins[0],vbins[1],vbins[2]),\
							np.linspace(omegabins[0],omegabins[1],omegabins[2])],dtype=object)

		ret_weightvals = scipy.stats.binned_statistic_dd(sample=sampledat,values=values,statistic=weighted_mean,bins=bin_list)
		sumweights = scipy.stats.binned_statistic_dd(sample=sampledat,values=weights,statistic='sum',bins=bin_list)
		ret_errs = scipy.stats.binned_statistic_dd(sample=sampledat,values=weights,statistic=weighted_mean_errs,bins=bin_list)
		x = ret_weightvals.bin_edges[0]
		y = ret_weightvals.bin_edges[1]
		z = ret_weightvals.bin_edges[2]
		print(np.shape(ret_weightvals.statistic))
		X,Y,Z = np.meshgrid(x,y,z)
		I = ret_weightvals.statistic[:,:,:]/sumweights.statistic[:,:,:]
		Err = ret_errs.statistic[:,:,:]
		if type(smooth)!=bool:
			#Smooth intensities, errors.
			old_nani = [np.isnan(I)]
			I[np.isnan(I)]=0
			Err[np.isnan(Err)]=0
			I = scipy.ndimage.gaussian_filter(I,sigma=smooth)
			Err = scipy.ndimage.gaussian_filter(Err,sigma=smooth)
			I[tuple(old_nani)]=np.nan 
			Err[tuple(old_nani)]=np.nan
		return X,Y,Z,I,Err

	def take_cut(self,ubins,vbins,omegabins,which_data='mcstas',statistic='mean'):
		"""
		Takes a cut of the data in the same style as MANTID.
			Syntax for bins are [min,max] - averaged (or integrated) within this limit
			[min,max,numBins] - cut axis, cut will be from min to max with that number of steps. Two of the three bins must be 
			integrated over.\n
		Integration not supported now- only mean in the region. 

		:param ubins: Binning along u-direction in format of [min,max,numBins] or [min,max]
		:type ubins: list
		:param vbins: Binning along v-direction in format of [min,max,numBins] or [min,max]
		:type vbins: list	
		:param omegabins: Binning along energy-axis in format of [min,max,numBins] or [min,max]
		:type omegabins: list	
		:param which_data: Determines if experimental or simulated data should be used, 
			'mcstas' to use calculated scattering and 'macs' for experimental. Allowed value 'mcstas' and 'macs'
		:type which_data: str
		:param statistic: Only mean is supported right now. Integration in the future. 
		:type statistic: str
		:return x,i,err: Returns three np arrays of the cut axis dimension coordinates, the intensities, and errors
			at this points. 	
		:rtype: np.ndarray, np.ndarray, np.ndarray	
		"""

		tot_binlength = len(ubins)+len(vbins)+len(omegabins)
		if tot_binlength!=7 or (len(ubins) not in [2,3]) or (len(vbins) not in [2,3]) or (len(omegabins) not in [2,3]):
			print('Cut specification invalid. Two dimensions must be in the form of [min,max], and the cut axis\n \
					should be in format of [min, max, numbins].')
			return 0,0,0
		if len(ubins)==3:
			cut_axis='Qu'
			bin_axis1 = 'Qv'
			bin_axis2 = 'DeltaE'
			bin_limit1 = vbins 
			bin_limit2 = omegabins
			cut_list = ubins 
			bin_list = np.array([np.linspace(ubins[0],ubins[1],ubins[2]),\
				bin_limit1,bin_limit2],dtype=object)
			dim_index = 0
		elif len(vbins)==3:
			cut_axis='Qv'
			bin_axis1 = 'Qu'
			bin_axis2 = 'DeltaE'
			bin_limit1 = ubins 
			bin_limit2 = omegabins 
			cut_list = vbins 
			bin_list = np.array([np.linspace(vbins[0],vbins[1],vbins[2]),\
				bin_limit1,\
				bin_limit2],dtype=object)
			dim_index=0
		elif len(omegabins)==3:
			cut_axis='DeltaE'
			bin_axis1 = 'Qu'
			bin_axis2 = 'Qv'
			bin_limit1 = ubins 
			bin_limit2 = vbins 
			cut_list = omegabins 
			bin_list = np.array([np.linspace(omegabins[0],omegabins[1],omegabins[2]),
				bin_limit1,bin_limit2],dtype=object)
			dim_index=0
		else:
			print('Cut specification invalid')
			return 0,0,0
		if which_data=='mcstas':
			df_copy = self.projected_matrix.copy()
		elif which_data=='macs':
			df_copy = self.projected_expt_matrix.copy()
		else:
			df_copy = self.projected_matrix.copy()
		df_copy = df_copy.loc[(df_copy[cut_axis]<=cut_list[1]) & (df_copy[cut_axis]>=cut_list[0])]
		df_copy = df_copy.loc[(df_copy[bin_axis1]<=bin_limit1[1]) & (df_copy[bin_axis1]>=bin_limit1[0])]
		df_copy = df_copy.loc[(df_copy[bin_axis2]<=bin_limit2[1]) & (df_copy[bin_axis2]>=bin_limit2[0])]
		#Data now restricted to the relevant region of Q-E space. Now bin:
		sampledat = np.array([df_copy[cut_axis].to_numpy(),df_copy[bin_axis1].to_numpy(),df_copy[bin_axis2].to_numpy()]).T
		values = df_copy['SPEC'].to_numpy().T
		errs = df_copy['SPECErr'].to_numpy().T 
		errs[errs==0]=np.nan
		weights = 1.0/errs 
		weights[np.isinf(weights)]=np.nan
		weighted_vals = values*weights
		def weighted_mean(weighted_vals):
			weighted_vals[np.isnan(weighted_vals)]=0 
			weighted_vals[np.isinf(weighted_vals)]=0 
			good_i = np.intersect1d(np.where(weighted_vals!=0)[0],np.where(~np.isnan(weighted_vals))[0])
			weighted_vals=weighted_vals[good_i]
			num = np.sqrt(np.nansum(weighted_vals))

			return num
		def weighted_mean_errs(weights):
			weights[weights==0]=np.nan 
			errs=1.0/weights 
			errs[errs==0]=np.nan
			return np.sqrt(np.nansum(errs**2))/np.nansum(weights)
		#Rather than simply computing the mean, we need to compute the weighted mean and its error bar. 
		ret_weightvals = scipy.stats.binned_statistic_dd(sample=sampledat,values=values,statistic=weighted_mean,bins=bin_list)
		sumweights = scipy.stats.binned_statistic_dd(sample=sampledat,values=weights,statistic='sum',bins=bin_list)
		ret_errs = scipy.stats.binned_statistic_dd(sample=sampledat,values=weights,statistic=weighted_mean_errs,bins=bin_list)
		x = ret_weightvals.bin_edges[dim_index]
		x = x[1:]-np.abs(x[1]-x[0])/2.0
		i = ret_weightvals.statistic[:,0,0]/sumweights.statistic[:,0,0]
		err = ret_errs.statistic[:,0,0]
		return x,i,err

	def fake_A3_scan(self,A3_angles):
		"""Function that fakes the rotation of the sample and simply copies the intensity at one angle over many.
			Will throw an error if multiple A3 angles exist in the data matrix already. 

		:param A3_angles: List of A3_angles to imitate
		:type A3_angles: list
		"""
		A3_arr = np.array(self.data_matrix['A3'].tolist())
		if len(np.unique(A3_arr))>1:
			print('Multiple A3 angles detected in current data matrix. This function will not work.')
			return 0
		else:
			#For each A3 angle, we take a copy of the original data matrix, edit the A3 value, 
			# and combine iteratively.
			orig_matrix = self.data_matrix.copy()
			tot_matrix = self.data_matrix.copy()
			for A3 in A3_angles:
				new_matrix = orig_matrix.copy()
				newA3 = np.ones(len(A3_arr))*A3
				new_matrix['A3']=newA3
				tot_matrix = pd.concat([tot_matrix,new_matrix])
			self.data_matrix=tot_matrix
		self.data_matrix.index = pd.RangeIndex(len(self.data_matrix.index))

		return 1

	def import_ng0_to_matrix(self,fname):
		"""Given a real MACS ng0 file, imports the result to the experimental data matrix. 

		:param fname: Filename of the ng0 file.
		:type fname: str
		"""
		data = np.genfromtxt(fname,dtype=str)
		column_labels={}
		file_params = {}
		f=open(fname,'r')
		lines = f.readlines()
		#Write all params to a dictionary
		for line in lines:
			param = line.split('\n')[0]
			param_name = param.split()[0].strip('#')
			param_val = param.split()[1:]

			file_params[param_name]=param_val
			if param_name=='Columns':
				#after this is data - break the loop. 
				break
		column_labels=file_params['Columns']
		#put this in a data_matrix like the previous one.
		col_labels=['A3','A2','A5','A6','H','K','L','Ei','Ef','DIFF','DIFF1','DIFF2','DIFF3','DIFF4','DIFF5','DIFF6','DIFF7','DIFF8','DIFF9','DIFF10','DIFF11',\
					'DIFF12','DIFF13','DIFF14','DIFF15','DIFF16','DIFF17','DIFF18','DIFF19','DIFF20','SPEC','SPEC1','SPEC2','SPEC3','SPEC4','SPEC5','SPEC6','SPEC7','SPEC8','SPEC9','SPEC10','SPEC11',\
					'SPEC12','SPEC13','SPEC14','SPEC15','SPEC16','SPEC17','SPEC18','SPEC19','SPEC20','Kidney','A4','Monitor','Time','AnalyzerTheta01','AnalyzerTheta02','AnalyzerTheta03','AnalyzerTheta04',\
					'AnalyzerTheta05','AnalyzerTheta06','AnalyzerTheta07','AnalyzerTheta08','AnalyzerTheta09','AnalyzerTheta10','AnalyzerTheta11','AnalyzerTheta12','AnalyzerTheta13','AnalyzerTheta14','AnalyzerTheta15',\
					'AnalyzerTheta16','AnalyzerTheta17','AnalyzerTheta18','AnalyzerTheta19','AnalyzerTheta20','PTAI',\
					'DIFF1Err','DIFF2Err','DIFF3Err','DIFF4Err','DIFF5Err','DIFF6Err','DIFF7Err','DIFF8Err','DIFF9Err','DIFF10Err','DIFF11Err',\
					'DIFF12Err','DIFF13Err','DIFF14Err','DIFF15Err','DIFF16Err','DIFF17Err','DIFF18Err','DIFF19Err','DIFF20Err',\
					'SPEC1Err','SPEC2Err','SPEC3Err',\
					'SPEC4Err','SPEC5Err','SPEC6Err','SPEC7Err','SPEC8Err','SPEC9Err','SPEC10Err','SPEC11Err',\
					'SPEC12Err','SPEC13Err','SPEC14Err','SPEC15Err','SPEC16Err','SPEC17Err','SPEC18Err','SPEC19Err','SPEC20Err']
		A3_list = np.array(data[:,file_params['Columns'].index('A3')]).astype(float)
		A2_list = np.array(data[:,file_params['Columns'].index('A2')]).astype(float)
		A4_list = np.array(data[:,file_params['Columns'].index('A4')]).astype(float)
		A6_list = np.array(data[:,file_params['Columns'].index('A6')]).astype(float)
		H_list = np.array(data[:,file_params['Columns'].index('H')]).astype(float)
		K_list = np.array(data[:,file_params['Columns'].index('K')]).astype(float)
		L_list = np.array(data[:,file_params['Columns'].index('L')]).astype(float)

		Ei_list = np.array(data[:,file_params['Columns'].index('Ei')]).astype(float)
		Ef_list = np.array(data[:,file_params['Columns'].index('Ef')]).astype(float)
		beta_1_list = np.array(data[:,file_params['Columns'].index('Beta1')]).astype(float)
		beta_2_list = np.array(data[:,file_params['Columns'].index('Beta2')]).astype(float)
		kid_list = np.array(data[:,file_params['Columns'].index('Kidney')]).astype(float)
		ptai_det = np.array(data[:,file_params['Columns'].index('PTAI')]).astype(int)

		#Need to normalize spec, diff to monitor
		monitor_list = np.array(data[:,file_params['Columns'].index('Monitor')]).astype(int)

		data_matrix = pd.DataFrame(index=np.arange(0,len(Ei_list),1),columns=col_labels)
		data_matrix['Ei']=Ei_list
		data_matrix['Ef']=Ef_list
		data_matrix['A3']=A3_list 
		data_matrix['Kidney']=kid_list 
		data_matrix['PTAI']=ptai_det
		data_matrix['H']=H_list 
		data_matrix['K']=K_list
		data_matrix['L']=L_list
		data_matrix['Monitor']=monitor_list

		#The rest are not as simple. iterate through detector indices
		for i in np.arange(1,21,1):

			if len(str(i))==1:
				indstr = '0'+str(i)
			else:
				indstr=str(i)
			anastr = 'AnalyzerTheta'+indstr 
			diffstr = 'DIFF'+indstr 
			specstr = 'SPEC'+indstr 
			diffstr_err = 'DIFF'+indstr+'Err'
			specstr_err = 'SPEC'+specstr+'Err'

			anastr_mat = 'AnalyzerTheta'+str(i)
			diffstr_mat = 'DIFF'+str(i)
			specstr_mat = 'SPEC'+str(i)
			diffstr_mat_err = 'DIFF'+str(i)+'Err'
			specstr_mat_err = 'SPEC'+str(i)+'Err'
			data_matrix.loc[:,diffstr_mat]=np.array(data[:,file_params['Columns'].index(diffstr)]).astype(float)
			data_matrix.loc[:,anastr_mat]=np.array(data[:,file_params['Columns'].index(anastr)]).astype(float)
			data_matrix.loc[:,specstr_mat]=np.array(data[:,file_params['Columns'].index(specstr)]).astype(float)
			data_matrix.loc[:,diffstr_mat_err]=np.sqrt(np.array(data[:,file_params['Columns'].index(diffstr)]).astype(float))
			data_matrix.loc[:,specstr_mat_err]=np.sqrt(np.array(data[:,file_params['Columns'].index(specstr)]).astype(float))

		#If there exists no expt data, we are done. 
		if type(self.expt_data_matrix) is bool:
			self.expt_data_matrix=data_matrix
		else:
			prev_mat = self.expt_data_matrix.copy()
			frames = [prev_mat,data_matrix]
			final_frame = pd.concat(frames)
			final_frame=final_frame.drop_duplicates(subset=['A3','Ei','Ef','Kidney'],keep='last')
			self.expt_data_matrix=final_frame
		return 1

	def write_data_to_ng0(self,filename='McStas_output_',beta_1=1.0,beta_2=1.0):
		"""Writes the current data matrix to an ng0 file directly readable by MSlice.
		:param filename: Output filename beginning. 
		:type filename: str
		"""
		#First open a file and write the header. 
		#Check if the file and output directory exists.
		current_dir = os.getcwd()
		if type(self.data_matrix)==bool:
			print('Need to generate data matrix before writing ng0.')
			return 1
		if not os.path.exists(current_dir+'/'+self.exptName+'/'+'Simulated ng0 files'):
			os.mkdir(current_dir+'/'+self.exptName+'/'+'Simulated ng0 files')
		output_dir = current_dir+'/'+self.exptName+'/'+'Simulated ng0 files/'
		#Simplest case, one large ng0 file. First open a file and write the header
		#If an old file exists, delete it.
		if filename.split('.')[-1]!='ng0':
			print("Filename requirement: must end in .ng0. Got "+str(filename))
		if os.path.exists(output_dir+filename+'.ng0'):
			os.remove(output_dir+filename+'.ng0')
		#output_file = open(output_dir+filename,'w')
		filename=output_dir+filename
		#output_file.close()
		self.writeHeader(filename)
		#Now iterate through the data matrix, appending each line to the file.
		f=open(filename,'a')
		for ind in self.data_matrix.index:
			#This is the format of the string:
			try:
				template_str ='                    N/A           N/A           N/A           N/A      A4             2         MONITOR       A2      A3       A5       A6       37.9822       37.9822           OUT         ANA_1         ANA_2         ANA_3         ANA_4         ANA_5         ANA_6         ANA_7         ANA_8         ANA_9         ANA_10         ANA_11         ANA_12         ANA_13         ANA_14         ANA_15         ANA_16         ANA_17         ANA_18         ANA_19         ANA_20           OUT        -18.7415           OUT       BETA_1       BETA_2      -190.585           DIFF           DIFF1           DIFF2           DIFF3           DIFF4          DIFF5          DIFF6          DIFF7          DIFF8          DIFF9          DIFF10          DIFF11          DIFF12        DIFF13         DIFF14          DIFF15          DIFF16          DIFF17          DIFF18          DIFF19          DIFF20            10       EF           Ei             A          1642      -1.03874 [-1.039,-1.039,0.076]      -1.03874      KIDNEY     0.0762141        3.9738            BE           OUT       -22.814       -22.976        -23.14       -23.301       -23.465       -23.629       -23.795        -23.96       -24.124       -24.292       -24.457       -24.626       -24.793       -24.961       -25.129       -25.299       -25.468       -25.638        -25.81        -25.98       -26.151        62.441         0.359             PTAI        OUT             0            SPEC            SPEC_1            SPEC_2            SPEC_3            SPEC_4           SPEC_5           SPEC_6           SPEC_7           SPEC_8           SPEC_9           SPEC_10           SPEC_11          SPEC_12         SPEC_13          SPEC_14           SPEC_15           SPEC_16           SPEC_17           SPEC_18           SPEC_19           SPEC_20          0.18        1.0101       -0.0008        0.0391       -15.001        359.99       360.008           OUT           OUT           OUT    1518'
				#All elements in caps are replaced by their respective simulated value.
				diff_str_list = ['DIFF'+str(int(ii))+' ' for ii in np.arange(1,21,1)]
				spec_str_list = ['SPEC_'+str(int(ii))+' ' for ii in np.arange(1,21,1)]
				ana_str_list = ['ANA_'+str(int(ii))+' ' for ii in np.arange(0,20,1)]

				#colstr = '{num:02d}'.format(num=i)
				ana_theta_val_list = []

				spec_val_list = ['{:.4f}'.format(self.data_matrix.loc[ind,'SPEC'+str(ii+1)]) for ii in np.arange(0,20,1)]
				diff_val_list = ['{:.4f}'.format(self.data_matrix.loc[ind,'DIFF'+str(ii+1)]) for ii in np.arange(0,20,1)]
				ana_theta_val_list =['{:.4f}'.format(self.data_matrix.loc[ind,'AnalyzerTheta'+'{num:02d}'.format(num=ii)]) for ii in np.arange(1,21,1)]

				replace_strs=['A4','MONITOR','A2','A3','A5','A6',*ana_str_list,\
					'BETA_1','BETA_2','DIFF ',*diff_str_list,'EF','Ei','KIDNEY','PTAI','SPEC ',*spec_str_list]

				replace_elements=['{:.4f}'.format(self.data_matrix.loc[ind,'A4']),\
					str(self.data_matrix.loc[ind,'Monitor']),'{:.4f}'.format(self.data_matrix.loc[ind,'A2']),\
					'{:.4f}'.format(self.data_matrix.loc[ind,'A3']),'{:.4f}'.format(self.data_matrix.loc[ind,'A5']),\
					'{:.4f}'.format(self.data_matrix.loc[ind,'A6']),\
					*ana_theta_val_list,'{:.4f}'.format(self.beta_1),'{:.4f}'.format(self.beta_2),\
					'{:.4f}'.format(self.data_matrix.loc[ind,'DIFF']),*diff_val_list,'{:.3f}'.format(self.data_matrix.loc[ind,'Ef']),\
					'{:.3f}'.format(self.data_matrix.loc[ind,'Ei']),'{:.4f}'.format(self.data_matrix.loc[ind,'Kidney']),\
					str(int(self.data_matrix.loc[ind,'PTAI'])),\
					'{:.3f}'.format(self.data_matrix.loc[ind,'SPEC']),*spec_val_list]

				for j in range(len(replace_elements)):
					template_str=template_str.replace(replace_strs[j],replace_elements[j])
				#Edit the string to have column width of the same length as ng0 files
				line_str_split = template_str.split()
				#The column widths were manually extracted from an example ng0 file.
				col_widths=[24, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 14, 16, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 22, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 22]

				writestr = "".join(line_str_split[i].rjust(col_widths[i]) for i in range(len(line_str_split)))+'\n'
				writestr = writestr #Mslice expects this padding for some reason. 
				#Finally, write to the file. 
				f.write(writestr)
			except Exception as e:
				print('Warning: ')
				print(e)
		endstr = '#NG0:END	TYPE= FP	FIT_P1= 123.172887	FIT_P2= 0.000000	FIT_P3= 0	FIT_P4= 772.040954	FIT_P5= -41.483096	FIT_P6= 0.502625'
		f.write(endstr)
		f.close()
		return 1

	def get_QE_FWHM(self,hkl_pt,omega,Q_dir):
		"""
		Gets FWHM values in Q and energy in Ang^-1 for a specified (h,k,l,omega) position. Requires a cut direction (longitudinal).
		The transverse direction is defined by the cross product of the +z vector and the cut direction. Returns a FWHM for the longitudinal, 
		transverse, and energy axes. A Q-resolution can also be specfied, but energy transfer is never binned.
		"""

		return 1
