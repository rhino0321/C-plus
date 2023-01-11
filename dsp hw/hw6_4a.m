N=60;
z=zeros(1,N);
w1=pi/3;
deltaw=pi/10;
for k=0:1:N-1
      z(k+1)=(cos(w1*k)+cos((w1+deltaw)*k));
end
y=fft(z,N);
t=0:1:N-1;
%stem
stem(t,abs(y))
title('X[k]')
xlabel('k')