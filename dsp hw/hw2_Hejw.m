N=20;
y=zeros(1,20);
Hejw=0;
for k=0:1:N-1
    wk=2*pi*k/N;
    if(sin(4*wk)==0&&(sin(wk/2)==0))%wk=0時需要用羅畢達法則
        y(k+1)=1;
    else
        y(k+1)=exp((-(1i)*7/2*wk))/8*sin(4*wk)/sin(wk/2);%代入化簡完的公式
    end
    Hejw=Hejw+y(k+1);
end