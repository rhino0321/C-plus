N=128;
y=zeros(1,128);
Xejw=0;
for k=0:1:N-1
    wk=2*pi*k/N;
    y(k+1)=exp(-(1i)*7/2*(wk-(pi/3)))*sin(4*(wk-(pi/3)))/sin((wk-(pi/3))/2);%代入化簡完的公式
    Xejw=Xejw+y(k+1);
end