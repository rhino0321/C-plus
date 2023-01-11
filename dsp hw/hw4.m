recObj = audiorecorder(8000,8,1,-1);%利用audiorecorder紀錄聲音,括號內8000為取樣頻率,8為nbits
recDuration = 3;%設定錄音時間
disp("Begin speaking.");
recordblocking(recObj,recDuration);%錄製聲音
disp("End of recording.");
y = getaudiodata(recObj);%將聲音轉為矩陣形式
plot(y);%利用plot作圖
