M=8;
Wk=zeros(1,20);%存放題目的Wk
N=20;
magnitude=zeros(1,20);%存放(sin4w)/sin(w/2)/8的大小頻譜
H1=zeros(1,20);%存放(sin4w)/sin(w/2)/8的頻譜
H2=zeros(1,20);%存放e^(-7/2Wk)的相位頻譜
p=zeros(1,20);%存放(sin4w)/sin(w/2)/8的相位頻譜
output=0;
for k=0:1:N-1
   Wk(k+1)=2*pi*k/N;%題目Wk公式
   magnitude(k+1)=sin(4*Wk(k+1))/sin(Wk(k+1)/2)/M;%將H(e^j^w)寫成sin,大小頻譜為|(sin4w)/sin(w/2)/8|
   H1(k+1)=sin(4*Wk(k+1))/sin(Wk(k+1)/2)/M;%將H(e^j^w)寫成sin,頻譜為(sin4w)/sin(w/2)/8
   H2(k+1)=-7/2*Wk(k+1);%exponential的相位
   if (magnitude(k+1)<0)%負數轉為正數
        magnitude(k+1)=-magnitude(k+1);
   elseif (sin(4*Wk(k+1))==0)&&(sin(Wk(k+1)/2)==0)%sin(4*Wk(k+1))/sin(Wk(k+1)/2)分子分母皆為0時,羅畢達法則推導後為1
        magnitude(k+1)=1;
        H1(k+1)=1;
   end
   p(k+1)=H1(k+1)/magnitude(k+1);%利用頻譜除以大小頻譜得到(sin4w)/sin(w/2)/8的相位頻譜
   if mod(k,5)==0%,k=5的倍數時,分子分母皆為0,雖然數學定義為undefined,但為了陣列運算我把值設為0
        p(k+1)=0;
   elseif (p(k+1)==1)%e^j0=1,角度為0
        p(k+1)=0;
   elseif (p(k+1)==-1)%e^jpi=-1,角度為pi
        p(k+1)=pi;
   end
end
t=0:1:N-1;
figure(1);
stem(t,magnitude);
title('|H(e^j^W^k)|');
xlabel('k');
figure(2);
stem(t,p+H2);%將兩組相位頻譜相加並作圖
xlabel('k');
title('phase freq, of H(e^j^W^k)');
Hejw=magnitude.*(exp(1i*(p+H2)));
for n=1:1:20
    output=output+Hejw(n);
end