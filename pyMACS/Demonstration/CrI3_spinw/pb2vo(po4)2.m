% First make the spinW object with ions in the correct places. 

CrI3 = spinw; 
CrI3.genlattice('lat_const',[8.747 9.016 9.863],'angled',[90 100.96 90],'spgr',14)
CrI3.addatom('r', [0.2558 0.4989 0.0623],'S', 1/2,'label','V4','color','blue')
CrI3.plot('range',[3 3 0.3])

% list the 1st 2nd 3rd 4th neighbor bonds
CrI3.gencoupling('maxDistance',8)
CrI3.table('bond',0:10)

%% Defining the spin Hamiltonian
% We create a matrix with a label 'Ja', ferromagnetic heisenberg
% interaction, J = -1 meV and assing it to the first neghbor bonds as
% spin-spin exchange interaction: J*S(i)*S(i+1). And plot the crystal
% structure with the added bonds.