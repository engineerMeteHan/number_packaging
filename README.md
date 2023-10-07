# number_packaging
When the program starts, it accepts a date between 1950 and 2077.(Lines 24-26)
Only some simple checks have been made; You cannot enter the 54th day of the 
13th month, but you can enter the 31st of February. Since we are only storing
the years since 1950, the -= operator in line 28 is performed. Packing is done
in line 29: the passing years in the year are shifted AY_UZ (i.e 4) bits to the 
left, the month is ORed into the newly vacated space, then the entire GUN_UZ (5)
bits are shifted left and the the day is ORed inward. At the end of the wrapping,
the leftmost 7 bşt of the date conrtain the years, the rightmost 5 bit contain 
the day, and the rest contain the month. In my system, since a short integer occupies 
16 bits, all bits in the TARIH are used. The range checks in the do clause are to ensure 
that none of these numbers will request more space than the amount located for them.

Line 32 is to eliminate any doubt as to whether the unpacking actually works and 
can be removed without causing any change in the program's behavior.

Line 33 gets the day by ANDing the day bits of the date with 1 and the rest with 0. 
This is called covering, for obvious reasons. The variable gun_ortu, initialized at 
line 20, contains the required bit pattern. (All bits of ~0 are 1.) 
Line 34 first shifts the date so that the month is in the rightmost 4 bits, 
then suppresses the bits other than the month to obtain the month. In line 35, 
the date is shifted to the right, resulting in elapsed years. Since the date is unsigned, 
there is always a 0 on the far left. The program ends by writing the newly opened date.
