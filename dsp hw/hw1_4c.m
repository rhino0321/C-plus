%4.(c)(1)(2)
M=8; % M-pt
N=51;%n從0到50,length為51;
output1=zeros(1,N+M-1);%設定答案的陣列皆為0,等等進入迴圈加入脈衝函數
output2=zeros(1,N+M-1);
h=[1 1 1 1 1 1 1 1]/M;%h[n]為8-pt moving average
g=[1 -1 1 -1 1 -1 1 -1]/M;%g[n]=(-1)^n*h[n];
for k=0:1:50
    y=zeros(1,N+M-1);%設定共51組位移的脈衝函數起始為0
    w=zeros(1,N+M-1);
    index=1;%陣列index
    for i=1:1:N+M-1
        if(i>=(k+1)&&i<=(k+8))%將h,w位移後的脈衝函數放入陣列,除了h[n-k]跟g[n-k],其他皆為0
            y(i)=h(index);
            w(i)=g(index);
            index=index+1;
        end
    end    
    output1=output1+(1.02^k+cos((2*pi*k/8)+pi/4))*y;%將51組h[n-k]加總
    output2=output2+(1.02^k+cos((2*pi*k/8)+pi/4))*w;%將51組w[n-k]加總
end
t=(0:1:N+M-2);%脈衝函數在0,1,2....N+M-2有值,利用stem,將t跟h[n-k]總和及t跟w[n-k]總和對應
stem(t,output1);
hold on;%為了將兩張圖做比較,使用hold on
stem(t,output2);
title('4.(c)');
xlabel('n');
ylabel('y[n] w[n]');
legend('y[n]','w[n]');