% First make the spinW object with ions in the correct places. 
symStr = 'x+1/2, -y+1/2, z; -x, -y, -z; -x+1/2, y+1/2, -z; x, y, z';
pbvpo=spinw;
pbvpo.genlattice('lat_const',[8.747 9.016 9.863],'angled',[90 100.96 90],'sym',symStr,'label','P 1 21/a 1')
pbvpo.addatom('r', [0.2558 0.4989 0.0623],'S', 1/2,'label','V4','color','blue')

% list the 1st 2nd 3rd 4th neighbor bonds
pbvpo.gencoupling('maxDistance',8)
pbvpo.table('bond',0:10)

%% Defining the spin Hamiltonian

% Referring to S. Bettler et al., PHYSICAL REVIEW B 99, 184437 (2019)

pbvpo.addmatrix('value',-0.286*eye(3),'label','J11','color','blue')
pbvpo.addmatrix('value',-0.389*eye(3),'label','J12','color','green')
pbvpo.addmatrix('value',-0.389*eye(3),'label','J13','color','red')
pbvpo.addmatrix('value',1.453*eye(3),'label','J21','color','black')
pbvpo.addmatrix('value',0.538*eye(3),'label','J22','color','orange')

pbvpo.addcoupling('mat','J11','bond',1)
pbvpo.addcoupling('mat','J12','bond',2)
pbvpo.addcoupling('mat','J13','bond',3)
pbvpo.addcoupling('mat','J21','bond',4)
pbvpo.addcoupling('mat','J22','bond',5)

%% Generate the magnetic structure
S0 = [0 0 0 0;
    0.5 0.5 -0.5 -0.5;
    0 0 0 0];
pbvpo.genmagstr('mode','tile','k',[0 0 0],'unit','lu', 'S',S0);
pbvpo.energy
pbvpo.optmagsteep()
pbvpo.energy
plot(pbvpo,'range',[-1 1; -1 1; 0.5 1.5])

%% Calc spin waves

nQh = 121;
nQk = 121;
nQl = 3;
nE = 91;
Qhv = linspace(-3,3,nQh);
Qkv = linspace(-3,0,nQk);
Qlv = linspace(-0.05,0.05,nQl);
[Qh, Qk, Ql] = ndgrid(Qhv,Qhv,Qlv);
E = linspace(0,3,nE);

% Create a list of Q point, with dimensions of [3 nQ^2].
Q = [Qh(:) Qk(:) Ql(:)]';

spec = pbvpo.spinwave(Q,'gtensor',false,'formfact',true);

Ev = E;
spec = sw_egrid(spec,'component','Sperp','Evect',Ev);
spec = sw_instrument(spec,'dE',0.05);

spec4D = reshape(spec.swConv,nE-1,nQh,nQk,nQl);
%%

hold on
figure('position',[20 20 800 500])
vmax=500;
E_slices = [0.5 1.0 1.5 1.75 2.0];
for i = 1:5
    subplot(3,2,i)
    E_slice = E_slices(i);
    dE = 0.1;
    Ecut = [E_slice-dE E_slice+dE]; %meV
    Eidx = find(Ev>Ecut(1) & Ev<Ecut(2));
    cut1 = squeeze(sum(spec4D(Eidx,:,:,:),[1,4]))/numel(Eidx)/(Ev(2)-Ev(1));

    %cut1(find(R.'>1.2))=NaN;
    %blur1 = imgaussfilt(cut1,2);
    imagesc(Qkv,Qhv,cut1);
    set(gca,'YDir','normal')
    xlabel('(0 K 0) (r.l.u.)')
    ylabel('(H 0 0) (r.l.u.)')
    titlestr = sprintf("E=%0.1f",E_slice);
    title(titlestr)


    %clim([0 vmax]);
end

%% Make a second series of constant energy slices, following SpinW tutorial 10 . 
nQh = 251;
nQk = 251;
nQl = 5;
nE = 151;
Qhv = linspace(-3,3,nQh);
Qkv = linspace(-3,3,nQk);
Qlv = linspace(-0.2,0.2,nQl);
[Qh, Qk, Ql] = ndgrid(Qhv,Qkv,Qlv);

% Create a list of Q point, with dimensions of [3 nQ^2].
Q = [Qh(:) Qk(:) Ql(:)]';

spec = pbvpo.spinwave(Q);

Ev = [0.5 1 1.5 1.75 2.0];
nE = size(Ev);
nE = nE(2);
spec = sw_egrid(spec,'component','Sperp','Evect',Ev);
spec = sw_instrument(spec,'dE',0.05);

spec4D = reshape(spec.swConv,nE-1,nQh,nQk,nQl);

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
        RL_mat = pbvpo.rl;
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
outmat_filtered(:,5)=outmat_filtered(:,5);

% Need to sort this by kinematic constraint. 
outmat_f = sortrows(outmat_filtered,6);
chki_vec = outmat_f(:,6);
% Remove chivec row
outmat_f(:,6)=[];

a = pbvpo.lattice.lat_const(1);
b = pbvpo.lattice.lat_const(2);
c = pbvpo.lattice.lat_const(3);
aa = rad2deg(pbvpo.lattice.angle(1));
bb = rad2deg(pbvpo.lattice.angle(2));
cc = rad2deg(pbvpo.lattice.angle(3));
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
movefile('out_full.txt','spinw_PbVOPO_full.sqw4')
