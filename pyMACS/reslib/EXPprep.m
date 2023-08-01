function EXP = EXPprep(H,K,L,W,EXP0)
[len,H,K,L,W]=CleanArgs(H,K,L,W);
for ii = 1:len
    EXP(ii) = EXP0;
    [EXP(ii).arms(1),EXP(ii).arms(2),EXP(ii).mono.rv,EXP(ii).mono.rh] =  MACSmono(EXP0,W(ii));    
end
end

