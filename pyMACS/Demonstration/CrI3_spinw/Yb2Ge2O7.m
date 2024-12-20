symStr = '-z, y+3/4, x+3/4; z+3/4, -y, x+3/4; z+3/4, y+3/4, -x; y+3/4, x+3/4, -z; x+3/4, -z, y+3/4; -z, x+3/4, y+3/4';

YGO = spinw;
a = 9.8297;
YGO.genlattice('lat_const',[a a a],'angled',[90 90 90],'spgr',symStr,'label','F d -3 m Z')
YGO.addatom('label','Yb3+','r',[1/2 1/2 1/2],'S',1/2)
YGO.addatom('label','Ge4+','r',[0 0 0])
YGO.addatom('label','O2-','r',[0.3318 1/8 1/8])
YGO.addatom('label','O2-','r',[3/8 3/8 3/8])
plot(YGO,'nMesh',3)
swplot.legend('none')

swplot.plotchem('atom1','Yb','atom2','O','limit',8,'range',[0.1 0.9;0.1 0.9;0.1 0.9]);

YGO.unit_cell = YGO.unitcell(1);

% We generate the list of bonds.
YGO.gencoupling

% We create two 3x3 matrix, one for the first neighbor anisotropic exchange
% and one for the anisotropic g-tensor. And assign them appropriately.

YGO.addmatrix('label','J1','value',1)
YGO.addmatrix('label','g0','value',1);

YGO.addcoupling('mat','J1','bond',1)
YGO.addg('g0')

gxy = 4.20; gz = 1.93;
A = 3.63; B=-0.76667;
YGO.matrix.mat(:,:,2) = [A B B; B A B; B B A];

YGO.getmatrix('mat','J1');

J1 = -0.01; J2 = -0.44; J3 = -0.37; J4 = -0.02;
YGO.setmatrix('mat','J1','pref',[J1 J3 J2 J4]);
plot(YGO,'ionMode','g')
swplot.zoom(1.3)
swplot.legend('none')

n = [1 -1 0];

B = 3;
%%

% set magnetic field
YGO.field(n/norm(n)*B);

% create fully polarised magnetic structure along the field direction
YGO.genmagstr('S',n','mode','helical');
% find best structure using steepest descendend
YGO.optmagsteep

nQh = 61;
nQk = 61;
nQl = 51;
nE = 41;
Qhv = linspace(-2.5*sqrt(2),2.5*sqrt(2),nQh);
Qkv = linspace(-0.27*sqrt(2),0.27*sqrt(2),nQk);
Qlv = linspace(-3.5,3.5,nQl);
[Qh, Qk, Ql] = ndgrid(Qhv,Qhv,Qlv);
E = linspace(0,3,nE);

% Create a list of Q point, with dimensions of [3 nQ^2].
Q = [Qh(:) Qk(:) Ql(:)]';
Q_rot = Q;
t = pi/4;
Rz = [cos(t) -sin(t) 0; sin(t) cos(t) 0; 0 0 1];
% Rotate the frame of reference so that the Qx = (HH0)
for i = 1:length(Q(1,:))
    Qvec = Q(:,i);
    Qvec_rot = Rz*Qvec;
    Q_rot(:,i)=Qvec_rot;

end
YGOSpec = YGO.spinwave(Q_rot,'gtensor',false,'formfact',true);

Ev = E;
YGOSpec = sw_egrid(YGOSpec,'component','Sperp','Evect',Ev);
YGOSpec = sw_instrument(YGOSpec,'dE',0.1);

spec4D = reshape(YGOSpec.swConv,nE-1,nQh,nQk,nQl);

%%

hold on
figure('position',[20 20 800 500])
vmax=500;
E_slices = [0.5 0.7 0.9 1.1 1.3 1.5];
for i = 1:6
    subplot(2,3,i)
    E_slice = E_slices(i);
    dE = 0.2;
    Ecut = [E_slice-dE E_slice+dE]; %meV
    Eidx = find(Ev>Ecut(1) & Ev<Ecut(2));
    cut1 = squeeze(sum(spec4D(Eidx,:,:,:),[1,3]))/numel(Eidx)/(Ev(2)-Ev(1));
    [Ql_mat,Qh_mat] = meshgrid((1/2.5)*Qhv/sqrt(2),(1/3.5)*Qlv);
    R = sqrt((Qh_mat).^2 + Ql_mat.^2);
    %cut1(find(R.'>1.2))=NaN;
    blur1 = imgaussfilt(cut1,2);
    imagesc(Qhv/sqrt(2),Qlv,blur1.');
    set(gca,'YDir','normal')
    xlabel('(H H 0) (r.l.u.)')
    ylabel('(0 0 L) (r.l.u.)')
    titlestr = sprintf("E=%0.1f",E_slice);
    title(titlestr)
    radius=3.5

    %clim([0 vmax]);
end
%%
`