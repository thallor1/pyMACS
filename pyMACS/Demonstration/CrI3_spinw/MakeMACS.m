function EXP=MakeMACS
% Generated by ResLibCal then modified manually by Y. Wang (Apr. 28, 2021)
% ReslibCal configuration script file: ResLibCal (Cooper-Nathans and Popovici)

% After loading EXP from this function, one should have
% (EXP.dir1 = -1, EXP.dir2 = 1) for sample scattering to left, analyzer to right;
% and (EXP.dir1 = 1, EXP.dir2 = -1) for sample scattering to right, analyzer to right;

%-------------------------   Computation type    -----------------------------------------
%EXP.method=0; %Cooper-Nathans approximation by default.
EXP.method=1; % Popovici approximation.
%EXP.moncor=1; % Intensity normalized to flux on monitor by default...
EXP.moncor=0; % Intensity normalization to white beam flux.


EXP.NMC = 200;

%-------------------------   Monochromator and analyzer    -------------------------------
EXP.mono.tau='PG(002)';     %PG(002), PG(004), GE(111), GE(220),GE(311),BE(002) or PG(110)...
EXP.mono.mosaic = 50;
EXP.mono.vmosaic = 50;
EXP.ana.tau = 'PG(002)';
EXP.ana.mosaic = 50;
EXP.ana.vmosaic = 50;
%-------------------------   Sample -------------------------------------------------------
EXP.sample.a = 2.0*pi;  %A: angstroms
EXP.sample.b = 2.0*pi;
EXP.sample.c = 2.0*pi;
EXP.sample.alpha = 90;  %Alpha: degrees of arc
EXP.sample.beta = 90;
EXP.sample.gamma = 90;
EXP.sample.mosaic = 30;  %Optional sample mosaic: minutes of arc
EXP.sample.vmosaic = 30;

%-------------------------   Soller and neutron guide collimation    ----------------------
% EXP.hcol = [180;180;90;120];
EXP.hcol = [900;900;90;120]; % no collimation
EXP.hcol = reshape(EXP.hcol, [1  4]);
EXP.vcol = [300;300;480;600];
EXP.vcol = reshape(EXP.vcol, [1  4]);

%-------------------------   Fixed neutron energy    --------------------------------------
EXP.efixed = 3.7;   %Fixed neutron energy in meV
EXP.infin=-1;      % Fixed final energy: default value
%EXP.infin=1;       % .. negative for fixed incident energy

%-------------------------   Experimental geometry    -------------------------------------
EXP.mono.dir = 1; %  Monochromator scattering angle is positive by default 
                  % (monochromator scattering is to left for my MACS experiment)
% EXP.dir1=1;        %  Monochromator scattering direction opposite to sample scattering by default (sample scattering to right)
EXP.dir1=-1;       %  ...negative if scattering directions are the same. (sample left)
EXP.dir2=1;        %  Analyzer scattering direction opposite to sample scattering by default 
%EXP.dir2=-1;       %  ...negative if scattering directions are the same.   
EXP.orient1 = [1;0;0];
EXP.orient1 = reshape(EXP.orient1, [1  3]);
EXP.orient2 = [0;1;0];
EXP.orient2 = reshape(EXP.orient2, [1  3]);


%-------------------------   Analyzer reflectivity parameters ----------------------------
% Do not assign these fields if no reflectivity corrections are to be made
EXP.ana.thickness=0.2;     %Analyzer thickness
EXP.ana.Q=0.1287;			%Kinematic reflectivity coefficient for PG(002)


%-------------------------   Horizontally focusing analyzer  ----------------------------
% These fields are used only if mode=0
EXP.horifoc = 1;  %Horizontally-focused analyzer
%EXP.horifoc=-1;  %Flat analyzer

%-------------------------   Spatial parameters     --------------------------------------
% All of these are optional and used only if mode=1 (Popovici approximation). 
% The default values correspond to the Cooper-Nathans limit.

% Component dimensions. For each object the "sizes" along a given coordinate axis X are 
% defined as sqrt( <x x> ). For a rectangular shape of width A along the Y axis, 
% for example, the correct input would be width=A/sqrt(12). For a spherical object
% of diameter D, one would input width=D/4.
EXP.beam.width = 8.9; %Width of source in length units
EXP.beam.height = 8.9; %Height of source in length units
EXP.detector.width = 5;
EXP.detector.height = 12;
EXP.mono.width = 36;
EXP.mono.height = 36;
EXP.mono.depth = 0.2;
EXP.ana.width = 6;
EXP.ana.height = 18;
EXP.ana.depth=0.2;
EXP.monitor.width = 10;
EXP.monitor.heigth = 24;

% The following matrix describes the sample shape. The components of S(i,j) matrix are  
% defined as <x_i x_j> for the sample. In ResMat it is assumed that this equation is written 
% in the coordinate system defined by the scattering vector. In ResMatS the sample coordinate 
% system, defined by the orienting vectors, is used instead.
EXP.sample.shape = [0.240833333333333;0;0;0;0.240833333333333;0;0;0;1.02083333333333];
EXP.sample.shape = reshape(EXP.sample.shape, [3  3]);    %In this example the rectangular sample is 1 
                                                         %units tall and 0.2 units in diameter.

% Spectrometer arms
EXP.arms = [620;168;100;25;434];
%EXP.arms = [400;400;100;25;434]; % TEST
EXP.arms = reshape(EXP.arms, [1  5]);  %Distances between the white beam aperture and monochromator,
                                       %monochromator and sample, sample and analyzer, analyzer and
                                       %detector, monochromator and monitor,
% Crystal curvatures
EXP.mono.rv = 280;  %vertical curvature radius of monochromator
EXP.mono.rh = 570; %(-1 in ResLibCal, thus calculated from L and theta.) 
                       %horizontal curvature radius of monochtor
EXP.ana.rv = 50; %vertical curvature radius of analyzer
EXP.ana.rh = 1e6; %horizontal curvature radius of analyzer (large number represent defocusing)