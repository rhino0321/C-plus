[y,Fs] = audioread('C:\Users\USER\Desktop\dsp\handel.wav');%將音檔讀進來
N=8192;%設定n-point
T=25;%由pitches結果大致求出週期
z=zeros(1,N);
x=fft(y,N);%dft
m=abs(x);%取大小
%為了取出-pi到pi頻譜,將右半邊頻譜放到-pi到0,0到pi則不變
for i=1:1:N
       if i>=1&&i<=(N/2)
           z(i)=m(N/2+i);
       else
           z(i)=m(i-N/2); 
       end
end
%時間軸設定
f = (-(N/2):length(x)/2-1)*2/N;
figure(1)
plot(f,z);
title('|Y(e^j^\omega)|')
xlabel('Freq. normalized by pi')
%取出角度,並設定在-pi到pi之間
p = unwrap(angle(x));
figure(2)
plot(f,p);
title('\angleY(e^j^\omega)')
xlabel('Freq. normalized by pi')
%改變時間軸大小
Yx = (-N/2:length(x)/2-1)*2/N/T;
%改變振幅大小
Yr=z.*T;
figure(3)
plot(Yx,Yr);
title('|Yr(j\Omega)|')
xlabel('\Omega')