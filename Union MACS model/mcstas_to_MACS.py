#Python Script to convert McStas output to MACS
#Thomas Halloran

import numpy as np
import sys
import os, os.path
import glob 
import time
rootdir = os.path.dirname(os.path.realpath(__file__))

# First, the script will assume that it is being in run in the directory of
# a single kidney angle scanned over A3

output_file_name = raw_input('Output file name : ')+'.ng0'
A3_steps = int(raw_input('Number of A3 Steps: '))
kidney_angle_num = int(raw_input('Number of kidney angles: '))
Total_number = A3_steps*kidney_angle_num
curr_time = time.clock()

#output_file_name = 'TiO2.ng0'

# This code will be taking intensity to be the same as counts, because in 
# Monte-Carlo simulations counts aren't meaningful

# Header info to be put at the top of text file every time:
# Need to make this customizable in the form of a config file / readin in from mcstas files:

# Lattice parameters can be adjusted here:

lattice_a = 4.594
lattice_b = 4.594
lattice_c = 2.959

theta_a = 90
theta_b = 90
theta_c = 90

orient_1 = '1 1 0'
orient_2 = '0 0 1'

line_str = '#Lattice     '+str(lattice_a)+' '+str(lattice_b)+' '+str(lattice_c)+' '+str(theta_a)+' '+str(theta_b)+' '+str(theta_c)+'\n'

def writeHeader(output_file):
	output_file.write('#ICE           0.4.0\n')
	output_file.write('#ICERepositoryInfo /ice/server/releases/ALL_2014_05_22 \n')
	output_file.write('#Filename    a3scan_elastic_1p6K_60273 \n')
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
	output_file.write('#Npoints     361\n')
	output_file.write('#TemperatureUnits Kelvin\n')
	output_file.write('#Ncolumns    137\n')
	output_file.write('#DetectorDims\n')
	output_file.write('#Signal      8 Monitor\n')
	output_file.write('#Reference   8 Monitor\n')
	output_file.write('#ScanType   ANGLE\n')
	output_file.write('#Scan        10 A3 \n')
	output_file.write('#ScanRanges: 10 A3 \n')
	output_file.write('#DetectorEfficiencies SPEC08=1.06822 DIFF08=1.0 SPEC13=1.02982 SPEC=1.0 DIFF12=1.0 DIFF06=1.0 DIFF20=1.0 SPEC18=1.65028 DIFF13=1.0 DIFF14=1.0 DIFF15=1.0 DIFF16=1.0 DIFF17=1.0 DIFF10=1.0 DIFF11=1.0 DIFF18=1.0 DIFF19=1.0 DIFF03=1.0 DIFF02=1.0 DIFF01=1.0 DIFF07=1.0 DIFF05=1.0 DIFF04=1.0 DIFF09=1.0 SPEC19=0.953006 SPARE=1.0 SPEC20=1.02213 Time=1.0 SPEC01=0.8707 SPEC10=0.791158 SPEC11=0.762235 SPEC14=1.15965 SPEC15=1.22142 SPEC16=1.00225 SPEC17=0.82556 SPEC12=0.807705 DIFF=1.0 SPEC06=0.914812 SPEC05=1.05829 SPEC04=0.842027 SPEC03=1.01165 SPEC02=1.06092 SPEC09=1.09363 SPEC07=0.854509 Monitor=1.0 \n')
	output_file.write('#FixedE     \n')
	output_file.write(line_str)
	output_file.write('#Orient      '+orient_1+' '+orient_2+'\n')
	output_file.write('#MonoSpacing 3.35416\n')
	output_file.write('#AnaSpacing  3.35416\n')
	output_file.write('#UBEnabled   0\n')
	output_file.write('#Fixed       All devices are free\n')
	output_file.write('#ScanDescr   Scan:SubID=20160727:JType=ANGLE:Npts=361:Counts=2600.0:Prefac=3.0:DetectorType=Monitor:CountType=Monitor:Filename=a3scan_elastic_1p6K_:HoldScan=0.0:Range=A3=-90.0 90.0 s:Title=a3scan_elastic\n')
	output_file.write('#Columns             QX            QY            QZ             E            A4          Time          Temp       Monitor            A2            A3            A5            A6           DFM            A1       AColMon AnalyzerTheta01 AnalyzerTheta02 AnalyzerTheta03 AnalyzerTheta04 AnalyzerTheta05 AnalyzerTheta06 AnalyzerTheta07 AnalyzerTheta08 AnalyzerTheta09 AnalyzerTheta10 AnalyzerTheta11 AnalyzerTheta12 AnalyzerTheta13 AnalyzerTheta14 AnalyzerTheta15 AnalyzerTheta16 AnalyzerTheta17 AnalyzerTheta18 AnalyzerTheta19 AnalyzerTheta20       BColMon BaseSampleTheta      BeFilMon         Beta1         Beta2        DFMDTS          DIFF        DIFF01        DIFF02        DIFF03        DIFF04        DIFF05        DIFF06        DIFF07        DIFF08        DIFF09        DIFF10        DIFF11        DIFF12        DIFF13        DIFF14        DIFF15        DIFF16        DIFF17        DIFF18        DIFF19        DIFF20          DMBT            Ef            Ei          FLIP         Focus             H           HKL             K        Kidney             L      MBTSlide          MCFX      MgFilMon    MonBlade01    MonBlade02    MonBlade03    MonBlade04    MonBlade05    MonBlade06    MonBlade07    MonBlade08    MonBlade09    MonBlade10    MonBlade11    MonBlade12    MonBlade13    MonBlade14    MonBlade15    MonBlade16    MonBlade17    MonBlade18    MonBlade19    MonBlade20    MonBlade21        MonRot      MonTrans          PTAI      PgFilMon         SPARE          SPEC        SPEC01        SPEC02        SPEC03        SPEC04        SPEC05        SPEC06        SPEC07        SPEC08        SPEC09        SPEC10        SPEC11        SPEC12        SPEC13        SPEC14        SPEC15        SPEC16        SPEC17        SPEC18        SPEC19        SPEC20     SmplLTilt     SmplUTilt         SmplX         SmplY         SmplZ          VBAH          VBAV         cfxbe       cfxhopg        cfxmgf TemperatureControlReading TemperatureSetpoint TemperatureHeaterPower TemperatureSensor2 TemperatureSensor3    timestamp\n')
	output_file.close()
output_file = open(output_file_name, 'w')
writeHeader(output_file)

def writeMatrix(matrix,output_file_name):
	np.savetxt('No_header_'+output_file_name,matrix,fmt='%s')

def getIntensity(file):
	file.seek(0)
	#Gets the Intensity total for both diff and spec files
	try:
		npArray = np.genfromtxt(file)
		Intensity = npArray[0:5]
		Ierr = npArray[5:10]
		N = npArray[10:15]
		#Note that we only care about intensity, as the MC simulation counts aren't meaningful
		TotIntensity = np.sum(Intensity)
		try:
			int(TotIntensity)
		except ValueError:
			TotIntensity=0
	except ValueError:
		TotIntensity=0
	return TotIntensity

def getParams(file):
	#Builds a dictionary of relevant params at top of the file
	#Note that non-param entries at top of file are nonsense in the dict 
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
		

	
# Create a class that makes an object for each detector file
# The object have a constructor for the following inputs from the diff_detector_x file:
#        -Table of intensities
#		 -Table of monitor counts
#		 -Calculated table of normalized intensities
#		 -A4  (functon of kidney_angle and detector number)
#        -A3  (Sample rotation)
#		 -EM  (Monochromator Energy to be converted to A2)
#        -EF  (Analyzer Energy to be converted to A6)
#

class MatRowObject:
	def __init__(self):
		self.Qx, self.Qy, self.Qz = 'N/A', 'N/A', 'N/A'
		self.E = 'N/A'
		self.A4 = 0# Ki - Kf 
		self.Time = 1#Make up a number for the config file
		self.Temp = 2#Put in config file
		self.Monitor = 780#Read in from line 47 in input file, NCount: x, or possibly make a standard number in the config file like 7800 since it isn't meaningful
		self.A2 = 74.2238#Angle from monochromator energy, calculate from EM line 13
		self.A3 = 5#Read in from line 11 
		self.A5 = 37.0862#Angle for analyzer energy, calculate from Ef_all line 14
		self.A6 = 74.1724#Not sure what this is, double of A5. I believe it's the 2nd analyzer ang.e
		self.DFM = 37.084 #No idea. Double focusing monochromator angle?
		self.A1 = 37.0834#I believe this is the source collimator angle, leave at something standard
		self.AcolMon = 'OUT'#Probably should just be OUT
		self.AnalyzerTheta = np.repeat(37.077,20)#Calculate from Ef_all, should be same as A5, angle for each detector
		self.BColMon = 'OUT' #Should be 'OUT'
		self.BaseSampleTheta = -56.8 # Not acactly sure, seems to go with A3
		self.BeFilMon ='OUT' #Probably should just be OUT
		self.Beta1 =3 #Don't know what this is.
		self.Beta2 =0.0001367 #Don't know what this is. 
		self.DFMDTS = -218.06#Don't know what this is. 
		self.DIFF = 100 #For use in Triple-axis mode
		self.DIFFi = np.repeat(0,20) #Sum of intensities rounded to closest value
		self.DMBT = 23156#Don't know what this is
		self.Ef = 5#Read in from file
		self.Ei = 5#Read in from file
		self.FLIP = 'A'#Probalby just A
		self.focus = 1617#Think it is 1617, check for double focusing.
		self.H = 0#going to have to write a routine to calcluate this
		self.HKL = np.array([0,1,0])#Array from calculated H K and L
		self.K = 1#write routine to calculate this
		self.Kidney = 0#Read in kidney_angle
		self.L =0 #Write a routine to calculate this
		self.MBTSlide = 5.4916#Don't know what this is. 5.4916
		self.MCFX = 'Be'#Go with "Be" I guess? 
		self.MgFilMon = 'OUT' # Guess this is out?
		self.MonBlade =np.repeat(0,21) #Could potentially read from file but should just be 20 length array of 0
		self.MonRot =0 #I assume this can be calculated from Ei?
		self.MonTrans = 0#Translation of monochromator, will need to find standard value.
		self.PTAI = 4 #Detector Number when instrument is operated in triple axis mode 
		self.PgFilMon = 'OUT'#Should be OUT
		self.SPARE = 0 #Should be 0
		self.SPEC = 1 #For use in triple-axis mode 
		self.SPECi = np.repeat(0,20) #Caclculate from spec_detector file
		self.SmplLTilt =200 #Get from somewhere?
		self.SmplUTilt = 0 #Made up
		self.SmplX =0 #Get from file
		self.SmplY = 0#Get from file
		self.SmplZ = 0#Get from file
		self.VBAH = 0 #?
		self.VBAV = 0 #?
		self.cfxbe= 0#?
		self.cfxhope= 0#?
		self.cfxmgf=1 #?
		self.TemperatureControlReading= 1#Put in config file
		self.TemperatureSetpoint= 1#Put in config file
		self.TemperatureHeaterPower=1 #Seems to ususally be 0
		self.TemperatureSensor2 = 1#Set to same as set point
		self.TemperatureSensor3 =1 #Set to same as set point
		self.timestamp= 563574#Make it up basically

#Set of column numbers for reference (ew):
#1: Qx
#2: Qy
#3: Qz
#4: E
#5: A4
#6: Time
#7: Temp
#8: Monitor
#9: A2
#10: A3
#11: A5
#12: A6
#13: DFM
#14: A1
#15: AColMon
#16: AnalyzerTheta
#17: BeFilMon
#18: Beta1
#19: Beta2
#20: DFMDTS
#21: Diff
#22: DMBT
#23: Ei
#24: EF
#25: FLIP
#26: focus
#26: H
#27: HKL
#28: K
#29: Kidney
#30: L
#31: MBTSLIDE
#32: MCFX
#33: Monblade
#34: MonRot
#35: MonTrans
#36: PTAI
#37: PgFilMon
#38: Spare
#39: SPEC
#40: SmplLTilt
#41: SmplX
#42: SmplY
#43: SmplZ
#44: VBAH
#45: VBAV
#46: cfxbe
#47: cfxhope
#48: cfxmgf
#49: TemperatureControlReading
#50: TemperatureSetpoint
#51: TemperatureHeaterPower
#52: TemperatureSensor2
#53: TempearatureSensor3
#54: Timestamp

#Create a numpy array that we will append to our ng0 file at the end

ng0Matrix = np.array([])
diffMatrix = np.array([])
specMatrix = np.array([])
A3_matrix = np.array([])
Kidney_matrix = np.array([])
Beta1_matrix=np.array([])
Beta2_matrix=np.array([])



# Write a loop to cycle through A3 directories
# Write a nested loop that creates a detectorObject from each file
# Append the self attributes contents of each DetectorObject to the np array
i=0
j=0
for subdirectory, directory, files, in os.walk(rootdir):
	
	#Initiate a new MatRowObject for the coming rows, this will happen for every subdirectory
	tempRow = MatRowObject()
	
	x=subdirectory.split('/')[-1]
	try:
		(int(x))
		j=int(x)
		i=i+1
	except ValueError:
		j=j
	
	for file in files:
		#This only works if the detector file names are unchanged
		#All of these entries will be compiled into a new row for the ng0Matrix
		
		#Determine the current number and type of file (spec or diff, detector num)
		filestr=str(file)
		filestrSplit = filestr.split("_")
		fileType = filestrSplit[0] #Should be 'diff' or 'spec'. Build in a filter for all other files
		fileextension = filestrSplit[-1]
		if filestrSplit[0] in ['diff','spec']:
			fileExt = filestrSplit[-1]
			fileNum = int(fileExt.split('.')[0])
			#print(str(file))
			f = open(subdirectory+'/' + str(file))
		if(fileType=='diff'):
			tempRow.DIFFi[fileNum]=getIntensity(f)
			#Get params like kidney angle and A3_angle from generated
			#dictionary, possibly more in future
			params = getParams(f)
			tempRow.A3=params['# Param: A3_angle']
			tempRow.Kidney = params['# Param: kidney_angle']
			tempRow.Beta1 = params['# Param: beta_1']
			tempRow.Beta2 = params['# Param: beta_2']
	
		if(fileType=='spec'):
			tempRow.SPECi[fileNum]=getIntensity(f)
			tempRow.A3=params['# Param: A3_angle']
			tempRow.Kidney = params['# Param: kidney_angle']
			tempRow.Beta1 = params['# Param: beta_1']
			tempRow.Beta2 = params['# Param: beta_2']
		
		
		#For now writing gibberish to the matrix othter than intensities to see if it all adds up to a proper numpy matrix
		
	
	#Correctly format the SPEC and DIFF arrays from their sub-arrays in their respective objects, i.e. make a numpy matrix of their results:
	
	diffRow = np.array([tempRow.DIFFi])
	specRow = np.array([tempRow.SPECi])
	A3_row = np.array([tempRow.A3])
	Kidney_Row = np.array([tempRow.Kidney])
	Beta1_row = np.array([tempRow.Beta1])
	Beta2_row = np.array([tempRow.Beta2])
	
	#Insert this row into the np array only if the subdirectory is named as expected, i.e. an integer
	try:
		int(x)
		diffMatrix = np.vstack((diffMatrix,diffRow)) if diffMatrix.size else diffRow
		specMatrix = np.vstack((specMatrix,specRow)) if specMatrix.size else specRow
		A3_matrix = np.vstack((A3_matrix, A3_row)) if A3_matrix.size else A3_row 
		Kidney_matrix = np.vstack((Kidney_matrix, Kidney_Row)) if Kidney_matrix.size else Kidney_Row
		Beta1_matrix = np.vstack((Beta1_matrix, Beta1_row)) if Beta1_matrix.size else Beta1_row
		Beta2_matrix = np.vstack((Beta2_matrix, Beta2_row)) if Beta2_matrix.size else Beta2_row
	except ValueError:
		j=j
	#All constant elements turned into numpy arrays outside of loop. 
	
	 
	
	#For sanity's sake print out a progress meter
	#currA3 = tempRow.A3
	#currKidney = tempRow.Kidney 
	#print("Current A3: "+str(currA3)+", Current Kidney Angle: "+str(currKidney))

	#Replaced with a percent progress
	i=i+1.0
	pct_done = 100.0*i/Total_number
	#only every 300 angles or so
	if (i%300==0):
		#curr_time = time.clock()-curr_time
		#Remaining time in minutes
		ETA = curr_time*(Total_number-i)/(60*300)
		print('Percent complete: '+str(pct_done))
		#print('Estimated remaining time: '+str(ETA) +'\n')

#Patch to adjust A3Steps to be right

A3Steps = len(A3_matrix)	

#Create numpy arrays for columns that will be constants (i.e. almost all of them).
tempobject = MatRowObject()
QxArray = np.repeat(tempobject.Qx, A3Steps)
QyArray = np.repeat(tempobject.Qy, A3Steps)
QzArray = np.repeat(tempobject.Qz, A3Steps)
E_array = np.repeat(tempobject.E, A3Steps)
A4_array = np.repeat(tempobject.A4, A3Steps)
TimeArray=np.repeat(tempobject.Time, A3Steps)
Temp_array = np.repeat(tempobject.Temp, A3Steps)
MonitorArray = np.repeat(tempobject.Monitor, A3Steps)
A2_array = np.repeat(tempobject.A2, A3Steps)

#Concatenate all entries before A3 into a matrix

pre_A3_matrix = np.column_stack((QxArray,QyArray,QzArray,E_array,A4_array,TimeArray,Temp_array, 
MonitorArray,A2_array))

#Create numpy arrays for columns that will be constans from A5 to Beta 1, then concatenate

A5_array = np.repeat(tempobject.A5, A3Steps)
A6_array = np.repeat(tempobject.A6, A3Steps)
DFMarray = np.repeat(tempobject.DFM, A3Steps)
A1_array = np.repeat(tempobject.A1, A3Steps)
AColMon_array = np.repeat(tempobject.AcolMon, A3Steps)
#A bit tricky but basically expand the array of Analyzer thetas into a matrix
AnalyzerTheta_Mat = np.tile(tempobject.AnalyzerTheta,(A3Steps,1))
BColMon_array = np.repeat(tempobject.BColMon, A3Steps)
BaseSampleTheta_array = np.repeat(tempobject.BaseSampleTheta, A3Steps)
BeFilMon_array = np.repeat(tempobject.BeFilMon, A3Steps)

post_A3_pre_Beta1 = np.column_stack((A5_array,A6_array,DFMarray,A1_array,AColMon_array,AnalyzerTheta_Mat,BeFilMon_array))

#Insert Beta1, Beta 2 into matrix later

#Beta1_array = np.repeat(tempobject.Beta1, A3Steps)
#Beta2_array = np.repeat(tempobject.Beta2, A3Steps)

#Insert Elements from Beta2 to DIFFi 

DFMDTS_array = np.repeat(tempobject.DFMDTS, A3Steps)
DIFF_array = np.repeat(tempobject.DIFF, A3Steps)


post_Beta2_pre_DIFFi = np.column_stack((DFMDTS_array, DIFF_array))

#All elements from DIFFi to Kidney

DMBT_array = np.repeat(tempobject.DMBT, A3Steps)
Ef_array = np.repeat(tempobject.Ef, A3Steps)
Ei_array = np.repeat(tempobject.Ei, A3Steps)
FLIP_array = np.repeat(tempobject.FLIP, A3Steps)
focus_array = np.repeat(tempobject.focus, A3Steps)
H_array = np.repeat(tempobject.H, A3Steps)
#Note again that HKL, MonBlade has to be treated like its own matrix
HKL_array = np.tile(tempobject.HKL, (A3Steps,1))
K_array = np.repeat(tempobject.K, A3Steps)

post_DIFFi_pre_Kidney= np.column_stack((DMBT_array,Ef_array,Ei_array, FLIP_array,focus_array,H_array,HKL_array,K_array))

#Insert all elements from Kidney to Spec

#Insert Kidney Matrix later

#Kidney_array = np.repeat(tempobject.Kidney, A3Steps)
L_array = np.repeat(tempobject.L, A3Steps)
MBTSlide_array = np.repeat(tempobject.MBTSlide, A3Steps)
MCFX_array = np.repeat(tempobject.MCFX, A3Steps)
MgFilMon_array = np.repeat(tempobject.MgFilMon, A3Steps)
MonBlade_array = np.tile(tempobject.MonBlade, (A3Steps,1))
MonRot_array = np.repeat(tempobject.MonRot, A3Steps)
MonTrans_array = np.repeat(tempobject.MonTrans, A3Steps)
PTAI_array = np.repeat(tempobject.PTAI, A3Steps)
PgFilMon_array= np.repeat(tempobject.PgFilMon, A3Steps)
SPARE_array = np.repeat(tempobject.SPARE, A3Steps)
SPEC_array = np.repeat(tempobject.SPEC, A3Steps)

#Lump into a matrix like before 

post_KIDNEY_pre_SPECi = np.column_stack((L_array,MBTSlide_array, MCFX_array, MgFilMon_array, MonBlade_array, MonRot_array, MonTrans_array, PTAI_array,
 PgFilMon_array, SPARE_array, SPEC_array))

#Finally, all elements after SPEC

SmplLTilt_array = np.repeat(tempobject.SmplLTilt, A3Steps)
SmplUTilt_array = np.repeat(tempobject.SmplUTilt, A3Steps)
SmplX_array = np.repeat(tempobject.SmplX, A3Steps)
SmplY_array = np.repeat(tempobject.SmplY, A3Steps)
SmplZ_array = np.repeat(tempobject.SmplZ, A3Steps)
VBAH_array = np.repeat(tempobject.VBAH, A3Steps)
VBAV_array = np.repeat(tempobject.VBAV, A3Steps)
cfxbe_array = np.repeat(tempobject.cfxbe, A3Steps)
cfxhope_array = np.repeat(tempobject.cfxhope, A3Steps)
cfxmgf_array = np.repeat(tempobject.cfxmgf, A3Steps)
TemperatureControlReading_array = np.repeat(tempobject.TemperatureControlReading, A3Steps)
TemperatureSetpoint_array = np.repeat(tempobject.TemperatureSetpoint, A3Steps)
TemperatureHeaterPower_array = np.repeat(tempobject.TemperatureHeaterPower, A3Steps)
TemperatureSensor2_array = np.repeat(tempobject.TemperatureSensor2, A3Steps)
TemperatureSensor3_array = np.repeat(tempobject.TemperatureSensor3, A3Steps)
Timestamp_array = np.repeat(tempobject.timestamp, A3Steps)

#concatenate into a matrix

post_SPEC = np.column_stack((SmplLTilt_array,SmplUTilt_array, SmplX_array,SmplY_array,SmplZ_array,VBAH_array,VBAV_array,cfxbe_array,cfxhope_array,cfxmgf_array,
TemperatureControlReading_array,TemperatureSetpoint_array,TemperatureHeaterPower_array,TemperatureSensor2_array,TemperatureSensor3_array, 
Timestamp_array))
	

#Concatenate all pre-A4 elements to A4
#For some reason the os.walk function doesn't do things sequentially. All data is in some random order, need to sort by A3 at the end
#Or just don't 

mat1 = np.concatenate((pre_A3_matrix,A3_matrix),axis=1)

#Concatenate this matrix with all elements from A5 to DIFF

mat2 = np.concatenate((mat1,post_A3_pre_Beta1),axis=1)

#Concatenate Beta1, Beta2, with mat2 

mat3 = np.concatenate((mat2,Beta1_matrix),axis=1)
mat4 = np.concatenate((mat3,Beta2_matrix),axis=1)

#Concatenate the post_Beta2_pre_DIFFi with mat4 

mat5 = np.concatenate((mat4,post_Beta2_pre_DIFFi),axis=1)

#Concatenate diffMatrix with mat5

mat6 = np.concatenate((mat5, diffMatrix),axis=1)

#Concatenate elements from post_DIFFi_pre_Kidney and before with mat6 

mat7 = np.concatenate((mat6,post_DIFFi_pre_Kidney),axis=1)

#Concatenate mat7, kidney_matrix 

mat8 = np.concatenate((mat7,Kidney_matrix),axis=1)

#Concatenate post_KIDNEY_pre_SPECi with mat8

mat9 = np.concatenate((mat8, post_KIDNEY_pre_SPECi),axis=1)

#Concatenate mat9 with specMatrix

mat10 = np.concatenate((mat9, specMatrix),axis=1)

#Concatenate everything else

finalMat = np.concatenate((mat10,post_SPEC),axis=1)

#Write the matrix to the Txt file!

writeMatrix(finalMat, output_file_name)

#Combine the two textfiles for our final result:
output_files = glob.glob("*.ng0")
output_files = [output_file_name, 'No_header_'+output_file_name]
with open('MSlice-'+output_file_name, "wb") as outfile:
	for f in output_files:
		with open(f, "rb") as infile:
			outfile.write(infile.read())

#First write the header:
#outfile = open('MSlice-'+output_file_name, 'wb')
#with open(output_file_name, 'rb'):
#	outfile.write(output_file_name.read())
#Then the data
#with open('No_header_'+output_file_name,'rb'):
#	outfile.write('No_header_'+output_file_name.read())
