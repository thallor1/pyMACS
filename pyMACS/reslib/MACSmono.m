function [L0, L1, rv, rh] = MACSmono(EXP0,W)
dm = 3.3542; % dspacing of mono in Å
Ei = EXP0.efixed + W; % incident neutron energy Ei = Ef + ΔE
Mtheta = asin(9.0446/sqrt(Ei)/2/dm); % Monochromator scattered angle in rad
d1 = 90; % in cm from MACS paper
d0 = 77.5;
L00 = EXP0.arms(1);
L0 = L00 - d0/tan(Mtheta*2); 
L1 = d1 + d0/sin(Mtheta*2);
rv = 2*sin(Mtheta)/(1/L0+1/L1);  %vertical curvature radius of monochromator
rh = sqrt(L0^2+L1^2+2*L0*L1*cos(Mtheta*2))/2/sin(Mtheta*2); % for horizontal focusing
disp(['Ei = ' num2str(Ei) 'meV, L0=' num2str(L0) ', L1=' num2str(L1) ', Rv=' num2str(rv) ', Rh=' num2str(rh)]);
end