N=1024;
L=100;
z=zeros(1,L);
for k=0:1:L-1
     z(k+1)=cos(pi/3*k);
end
y=fft(z,N);
t=0:1:N-1;
plot(t./512,abs(y));
title('|Y(e^j^\omega)|')
xlabel('Freq. normalized by \pi')