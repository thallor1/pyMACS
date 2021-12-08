import numpy as np

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
	def __init__(self,repeat_count=1,Ei=5.0,HF=1,VF=1,beta_1=1.0,beta_2=1.0,misalign_deg=0.15,slit_h=0.2,slit_v=0.2,MPL=6.06,MPD=0.775,\
		DIRDEV=0.0,DIVSOU=3.0,L0_delta=-1.06,L1_delta=0.0,mon_t=0.0,mon_e=0.0,monrot_delta=0.0):
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

	#Eventually add a function to calculate optimal betas. 
	