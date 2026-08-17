%==========================================

function dtmfsig = dtmfdial(nums,fs)
%DTMFDIAL  Create a vector of tones which will dial 
%           a DTMF (Touch Tone) telephone system.
%
% usage:  dtmfsig = dtmfdial(nums) 
%      nums = vector of numbers ranging from 1 to 12
%        fs = sampling frequency
%   dtmfsig = vector containing the corresponding tones.
%
  
tone_cols = ones(4,1)*[1209,1336,1477];
tone_rows = [697;770;852;941]*ones(1,3);

%==========================================

 function keys = dtmfrun(xx,L,fs)
 %DTMFRUN    keys = dtmfrun(xx,L,fs)
 %    returns the list of key names found in xx.
 %   keys = array of characters, i.e., the decoded key names
 %     xx = DTMF waveform
 %      L = filter length
 %     fs = sampling freq
 %

 center_freqs = .... %<============================FILL IN THE CODE HERE
 hh = dtmfdesign( center_freqs,L,fs );
 %   hh = L by 8 MATRIX of all the filters. Each column contains the
 %         impulse response of one BPF (bandpass filter)
 %
 [nstart,nstop] = dtmfcut(xx,fs);   %<--Find the tone bursts
 keys = [];
 for kk=1:length(nstart)
    x_seg = xx(nstart(kk):nstop(kk));    %<--Extract one DTMF tone
 ....   %<=========================================FILL IN THE CODE HERE
end

%==========================================
function  sc = dtmfscore(xx, hh)
%DTMFSCORE
%          sc = dtmfscore(xx, hh)
%    returns a score based on the maximum amplitude of the filtered output
%     xx = input DTMF signal
%     hh = impulse response of ONE bandpass filter
%
%   The signal detection is done by filtering xx with a length-L
%   BPF, hh, and then finding the maximum amplitude of the output.
%   The score is either 1 or 0.
%      sc = 1 if max(|y[n]|) is greater than, or equal to, 0.45
%      sc = 0 if max(|y[n]|) is less than 0.45
%

xx = 2*xx/max(abs(xx));   %---Scale x[n] to the range [-2,+2]

%==========================================

function  hh = dtmfdesign(fcent, L, fs)
%DTMFDESIGN
%     hh = dtmfdesign(fcent, L, fs)
%       returns a matrix where each column is the
%       impulse response of a BPF, one for each frequency
%  fcent = vector of center frequencies
%      L = length of FIR bandpass filters
%     fs = sampling freq  
%
%   The BPFs must be scaled so that the maximum magnitude
%    of the frequency response is equal to one.
%

%==========================================

