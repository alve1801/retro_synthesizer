# retro_synthesizer
An 8-bit synthesizer that I wrote one night for the funzies during a sleepover and then spent the rest of the night transcribing "Megalovania" to it.

As it was meant to be straightforward, it uses ASCII values to encode tones (except for 32 (the spacebar), which denotes a pause. So if you want to play a D2, you're out of luck).

It also requires some metadata at the beginning of the file. On the first line is a single digit denoting how many tracks are used. On the next line is a number denoting the duration of each 'note' (in 40ths of a second), and then the length of the tracks (they have to all be equal length for now). Included are some samples which might help.
