% Ramp waveform example file for the Rigol DG1022 function generator.
% Saves an .rdf file that can be loaded into the Rigol DG1022

clear all

% Create a simple ramp function for the arbitrary waveform generator

Npts = 8192;            % Number of points to save
s(1) = 0;               % First sample of the waveform
for n = 2 : Npts        % Loop through all points and create
    s(n) = s(n-1) + 4;  % Add 4 to each sample to ramp 0 to 32768
    if s(n) > 32767     % For other increments, wrap to zero
        s(n) = 0;
    end
end
s_fp = uint16( s );     % Create a 16-bit integer, but let's be specific.

% Save the samples to disk

Filename = 'Ramp.rdf';                     % Store in this file
fid = fopen( Filename, 'w' );              % Open the file for writing    
fwrite( fid, s_fp, 'uint16', 'ieee-be' );  % Write as 16-bit values, little endian
fclose( fid );                             % Close file

hold on;
figure(1);
% Define colors
green = [0.9 1 0.8];
red = [1 0.9 0.8];

ylabel('Amplitude');
xlabel('NSample');
plot([0:length(s)-1], s, 'r*');
