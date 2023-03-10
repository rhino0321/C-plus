N=120000;
Y=2*abs(fft(y))/N;
b=0:N-1;
f=(b*Fs/N)./8000;
blo=fir1(58,0.1,kaiser(59,8));
outlo = filter(blo,1,y);
outmag=fft(outlo);
t = (0:N-1);
subplot(4,1,1);
plot(t,y);
title('initial y[n]');
xlabel('n');
subplot(4,1,2);
plot(f,real(Y));
title('initial Y(e^j^\omega)');
xlabel('\omega normalized by \pi');
subplot(4,1,3);
plot(t,outlo);
title('filter y[n]');
xlabel('n');
subplot(4,1,4);
plot(f,real(outmag));
title('filter Y(e^j^\omega)');
xlabel('\omega normalized by \pi');
soundsc(outlo);