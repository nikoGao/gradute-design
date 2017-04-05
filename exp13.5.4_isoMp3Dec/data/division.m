fid = fopen('pcmFile.pcm', 'rb');
pcmData = fread(fid, 'int16');
len = length(pcmData);
leftChannel = pcmData(1:2:len-1);
rightChannel = pcmData(2:2:len);
subplot(2,1,1);plot(leftChannel);
subplot(2,1,2);plot(rightChannel);
soundsc(leftChannel,44100);
soundsc(rightChannel,44100);