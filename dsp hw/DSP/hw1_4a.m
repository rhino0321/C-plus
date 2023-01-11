%4.(a)
M=8;%8-pt moving average
n=0:1:7;%脈衝在n=0,1...7有值
h=ones(1,8)/M;%設定陣列長度8,值為1/8
stem(n,h);%n,h為相同長度陣列下,畫出二維的圖形,其中n跟h的值在index互相對應
title('4.(a)');
xlabel('n');
ylabel('h[n]');