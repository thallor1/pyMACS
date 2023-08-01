% First make the spinW object with ions in the correct places. 

CrI3 = spinw; 
CrI3.genlattice('lat_const',[6.867 6.867 19.807],'angled',[90 90 120],'spgr',148)
CrI3.addatom('r', [0 0 0.1663],'S', 3/2,'label','Cr3','color','blue')
CrI3.plot('range',[3 3 0.3])

% list the 1st 2nd 3rd 4th neighbor bonds
CrI3.gencoupling('maxDistance',8)
CrI3.table('bond',0:10)

%% Defining the spin Hamiltonian
% We create a matrix with a label 'Ja', ferromagnetic heisenberg
% interaction, J = -1 meV and assing it to the first neghbor bonds as
% spin-spin exchange interaction: J*S(i)*S(i+1). And plot the crystal
% structure with the added bonds.
 
CrI3.addmatrix('value',-2.01*eye(3),'label','J1','color','green')
CrI3.addmatrix('value',-0.16*eye(3),'label','J2','color','red')
CrI3.addmatrix('value',0.08*eye(3),'label','J3','color','blue')
CrI3.addmatrix('value',-0.59*eye(3),'label','Jc','color','black')
CrI3.addmatrix('label','DM1','value',[0 0 -0.31],'color','green')

CrI3.addmatrix('value',diag([0 0 -0.22]),'label','Dz','color','r')

CrI3.addcoupling('mat','J1','bond',1)
CrI3.addcoupling('mat','DM1','bond',3)
CrI3.addcoupling('mat','J2','bond',3)
CrI3.addcoupling('mat','J3','bond',6)
CrI3.addcoupling('mat','Jc','bond',2)
CrI3.addaniso('Dz')
plot(CrI3,'range',[2.5 2.5 1],'cellMode','none','baseMode','none')

%% Generate the magnetic structure
S0 = [0 0 0 0 0 0;
    0 0 0 0 0 0;
    1.5 1.5 1.5 1.5 1.5 1.5];
CrI3.genmagstr('mode','tile','k',[0 0 0],'unit','lu', 'S',S0);
CrI3.energy
CrI3.optmagsteep()
CrI3.energy
plot(CrI3,'range',[3 3 0.2],'cellMode','none','baseMode','none')

%% Plot spin wave excitation spectra
hold on 
Qlist = {[-2 0 0] [2 0 0] 300};
E = linspace(0,22,200);

spec = CrI3.spinwave(Qlist,'hermit',false,'gtensor',true);
spec = sw_neutron(spec);
spec = sw_egrid(spec,'component','Sperp','Evect',E,'imagChk',false,'binType','ebin');
spec = sw_instrument(spec,'dE',0.1,'norm',false,'fid',0,'dQ',0.02);
figure
sw_plotspec(spec,'colormap','parula','legend',false,'colorbar',true)
colormap parula
colorbar
clim([0 10])

%% Now save this along with the proper header to a .sqw4 file using iFit.

%Note that in general points should be spaced out such that the have the
%same volume in cartesian Q-w space. 
Intensity = transpose(spec.swConv);
Qvecs = spec.hkl;
hvec = transpose(Qvecs(1,:));
kvec = transpose(Qvecs(2,:));
lvec = transpose(Qvecs(3,:));
Evec = transpose(spec.Evect);
shape = size(Intensity);
shapeE = size(E);
% Allocate output of shape (num_slices * num_energy * num_hkl, 5) where
% each column is H K L E I chki
outmat = zeros(shape(1)*shape(2),6);
count = 1;
for i=1:shape(1)
    h = hvec(i);
    k = kvec(i);
    l = lvec(i);
    for j=1:shape(2)
        omega = Evec(j);
        I_pt = Intensity(i,j);
        RL_mat = CrI3.rl;
        astar_vec = RL_mat(1,:);
        bstar_vec = RL_mat(2,:);
        cstar_vec = RL_mat(3,:);
        Q = h.*astar_vec + k.*bstar_vec + l.*cstar_vec;
        Qmod = vecnorm(Q);
        neutron_const = 0.4826966246;
        chki = (Qmod + (neutron_const*omega/Qmod))/2.0;
        outmat(count,:) = [h k l omega I_pt chki];
        count=count+1;
    end
end

% Filter out low intensity points. 
min_I = max(outmat(:,5))*1e-4;
good_i = outmat(:,5)>min_I;
outmat_filtered=outmat(good_i,:);
% Divide by a large factor to scale intensities. 
outmat_filtered(:,5)=outmat_filtered(:,5)/1e3;

% Need to sort this by kinematic constraint. 
outmat_f = sortrows(outmat_filtered,6);
chki_vec = outmat_f(:,6);
% Remove chivec row
outmat_f(:,6)=[];

a = CrI3.lattice.lat_const(1);
b = CrI3.lattice.lat_const(2);
c = CrI3.lattice.lat_const(3);
aa = rad2deg(CrI3.lattice.angle(1));
bb = rad2deg(CrI3.lattice.angle(2));
cc = rad2deg(CrI3.lattice.angle(3));
% Make a header,save the output matrix. 

formatspec = ['# 	lattice_a %0.5f\n',....
	'# 	lattice_b %0.5f\n',....
	'# 	lattice_c %0.5f\n',....
	'# 	lattice_aa %0.2f\n',....
	'# 	lattice_bb %0.2f\n',....
	'# 	lattice_cc %0.2f\n',....
	'# 	temperature 2\n',....
	'# 	field||a 0\n',....
	'# 	field||b 0\n',....
	'# 	field||c 0\n',....
	'# 	column_h 1\n',....
	'# 	column_k 2\n',....
	'# 	column_l 3\n',....
	'# 	column_E 4\n',....
	'# 	column_S 5\nh k l En S(q,w)'];

header = sprintf(formatspec,a,b,c,aa,bb,cc);
headerlines = convertStringsToChars(header);

writelines(headerlines,'out.txt')
writematrix(outmat_f,'out.txt','Delimiter','space','WriteMode','append')
%Rename the file to sqw4.
movefile('out.txt','spinw_CrI3.sqw4')

%% Make a second series of constant energy slices, following SpinW tutorial 10 . 
nQh = 151;
nQk = 101;
nQl = 5;
nE = 151;
Qhv = linspace(-2,2,nQh);
Qkv = linspace(0,2,nQk);
Qlv = linspace(-0.5,0.5,nQl);
[Qh, Qk, Ql] = ndgrid(Qhv,Qkv,Qlv);

% Create a list of Q point, with dimensions of [3 nQ^2].
Q = [Qh(:) Qk(:) Ql(:)]';

spec = CrI3.spinwave(Q);

Ev = linspace(0,25,nE);
spec = sw_egrid(spec,'component','Sperp','Evect',Ev);
spec = sw_instrument(spec,'dE',0.05);

spec4D = reshape(spec.swConv,nE-1,nQh,nQk,nQl);

Ecut = [5.5 6.0]; %meV
Eidx = find(Ev>Ecut(1) & Ev<Ecut(2));
hold on
figure;
cut1 = squeeze(sum(spec4D(Eidx,:,:,:),[1,4]))/numel(Eidx)/(Ev(2)-Ev(1));
imagesc(Qhv,Qkv,cut1);
set(gca,'YDir','normal')
xlabel('(H 0 0) (r.l.u.)')
ylabel('(0 K 0) (r.l.u.)')
title('Spin wave spectrum at E = 3 meV, square lattice Heisenberg AF')
caxis([0 3])

colorbar

% Now flatten into a single output matrix and sort by the chki 
%Note that in general points should be spaced out such that the have the
%same volume in cartesian Q-w space. 
Intensity = transpose(spec.swConv);
Qvecs = spec.hkl;
hvec = transpose(Qvecs(1,:));
kvec = transpose(Qvecs(2,:));
lvec = transpose(Qvecs(3,:));
Evec = transpose(spec.Evect);
shape = size(Intensity);
shapeE = size(E);
% Allocate output of shape (num_slices * num_energy * num_hkl, 5) where
% each column is H K L E I chki
outmat = zeros(shape(1)*shape(2),6);
count = 1;
for i=1:shape(1)
    h = hvec(i);
    k = kvec(i);
    l = lvec(i);
    for j=1:shape(2)
        omega = Evec(j);
        I_pt = Intensity(i,j);
        RL_mat = CrI3.rl;
        astar_vec = RL_mat(1,:);
        bstar_vec = RL_mat(2,:);
        cstar_vec = RL_mat(3,:);
        Q = h.*astar_vec + k.*bstar_vec + l.*cstar_vec;
        Qmod = vecnorm(Q);
        neutron_const = 0.4826966246;
        chki = (Qmod + (neutron_const*omega/Qmod))/2.0;
        outmat(count,:) = [h k l omega I_pt chki];
        count=count+1;
    end
end

% Filter out low intensity points. 
min_I = max(outmat(:,5))*1e-4;
good_i = outmat(:,5)>min_I;
outmat_filtered=outmat(good_i,:);
% Divide by a large factor to scale intensities. 
outmat_filtered(:,5)=outmat_filtered(:,5)/1e3;

% Need to sort this by kinematic constraint. 
outmat_f = sortrows(outmat_filtered,6);
chki_vec = outmat_f(:,6);
% Remove chivec row
outmat_f(:,6)=[];

a = CrI3.lattice.lat_const(1);
b = CrI3.lattice.lat_const(2);
c = CrI3.lattice.lat_const(3);
aa = rad2deg(CrI3.lattice.angle(1));
bb = rad2deg(CrI3.lattice.angle(2));
cc = rad2deg(CrI3.lattice.angle(3));
% Make a header,save the output matrix. 

formatspec = ['# 	lattice_a %0.5f\n',....
	'# 	lattice_b %0.5f\n',....
	'# 	lattice_c %0.5f\n',....
	'# 	lattice_aa %0.2f\n',....
	'# 	lattice_bb %0.2f\n',....
	'# 	lattice_cc %0.2f\n',....
	'# 	temperature 2\n',....
	'# 	field||a 0\n',....
	'# 	field||b 0\n',....
	'# 	field||c 0\n',....
	'# 	column_h 1\n',....
	'# 	column_k 2\n',....
	'# 	column_l 3\n',....
	'# 	column_E 4\n',....
	'# 	column_S 5\nh k l En S(q,w)'];

header = sprintf(formatspec,a,b,c,aa,bb,cc);
headerlines = convertStringsToChars(header);

writelines(headerlines,'out_full.txt')
writematrix(outmat_f,'out_full.txt','Delimiter','space','WriteMode','append')
%Rename the file to sqw4.
movefile('out_full.txt','spinw_CrI3_full.sqw4')


