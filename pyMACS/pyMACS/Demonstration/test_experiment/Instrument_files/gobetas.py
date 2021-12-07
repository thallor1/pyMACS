#Python script to imitate IDL gobetas.pro for MACS

import lmfit 
import numpy as np
from lmfit import Model,Parameters

'''
For reference, this is the IDL function being imitated

function betas,tt,dmbt
    tt_all    =  [43.,50.,60.,70.,80.,90.,100.,110.,120.]
    dmbt_all=[5,10,15,20,25.]  
    ttc_mat_b1 = fltarr(n_elements(dmbt_all))
    ttc_mat_b2 = fltarr(n_elements(dmbt_all))  
    beta1_20 =  [0.3,0.45,0.7,0.87,0.87,1.10,1.14,1.20,1.28]
    beta2_20 =  [1.66,2.08,2.12,2.20,2.23,2.19,2.17,2.07,2.00]
    beta1_10 = [0.4, 0.63, 0.8, 0.95, 1.22, 1.29, 1.45, 1.57, 1.58]
    beta2_10 = [2.07, 2.02, 2.13, 2.18, 2.32, 2.30, 2.21, 2.07, 2.05]
    beta1_5 =[0.7, 1.19, 1.32, 1.30, 1.40, 1.57, 1.70, 1.71, 2.0]
    beta2_5 = [2.28, 2.55, 2.49, 2.69, 2.52, 2.43, 2.44, 2.21, 2.21]
    beta1_15=[0.43, 0.41, 0.58, 0.77, 0.95, 1.13, 1.21, 1.43, 1.35]
    beta2_15=[2.09, 2.12, 2.22, 2.31, 2.28, 2.17, 2.14, 2.11, 2.02]
    beta1_25=[0.1, 0.16, 0.23, 0.58, 0.68, 0.92, 1.08, 1.10, 1.16]
    beta2_25=[1.68, 2.14, 2.20, 2.39, 2.23, 2.16, 2.17, 2.01, 1.98]
    dbeta1   = [0.05, 0.03, 0.03, 0.02 ,0.04, 0.03, 0.05, 0.03, 0.04]
    dbeta2   = [0.02, 0.01, 0.01, 0.03, 0.03, 0.02, 0.03, 0.02, 0.02]   
    all_betas1=[ [beta1_5], [beta1_10], [beta1_15],[beta1_20], [beta1_25]]
    all_betas2=[ [beta2_5], [beta2_10], [beta2_15],[beta2_20], [beta2_25]]
    for nn=0,4 do begin
      pbeta1=poly_fit(tt_all,all_betas1[*,nn],5,MEASURE_ERRORS=dbeta1)
      pbeta2=poly_fit(tt_all,all_betas2[*,nn],5,MEASURE_ERRORS=dbeta2)
      polynomial,tt,pbeta1,xx
      ttc_mat_b1[nn]=xx
      polynomial,tt,pbeta2,xx
      ttc_mat_b2[nn]=xx 
    endfor     
    pbeta1=poly_fit(dmbt_all,ttc_mat_b1,3)
    pbeta2=poly_fit(dmbt_all,ttc_mat_b2,3)
    polynomial,dmbt,pbeta1,beta1c
    polynomial,dmbt,pbeta2,beta2c 
   return,[beta1c,beta2c]
end

'''

def calc_betas(plotbetas,dmbt):
	#Imitates MACS IDL script to determine beta1 beta2 for specific dmbt setting
	#Data for DMBT=20
	tt = np.array([43.,50.,60.,70.,80.,90.,100.,110.,120.])
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

	allbetas1 = np.array([beta1_dmbt5],[beta1_dmbt10],[beta1_dmbt15],[beta1_dmbt20],[beta1_dmbt25])
	allbetas2 = np.array([beta2_dmbt5],[beta2_dmbt10],[beta2_dmbt15],[beta2_dmbt20],[beta2_dmbt25])
	dbeta1   = np.array([0.05, 0.03, 0.03, 0.02 ,0.04, 0.03, 0.05, 0.03, 0.04])
	dbeta2   = np.array([0.02, 0.01, 0.01, 0.03, 0.03, 0.02, 0.03, 0.02, 0.02])

	model = lmfit.models.PolynomialModel(degree=5,independent_vars=['tt'],nan_policy='raise')
	#Fit betas as a function of tt, with errors specified above.
	weights1 = 1.0/dbeta1
	weights2 = 1.0/dbeta2
	


	