#meretezes, kimenet beallitasa

set term pngcairo size 1280,720

set output "en.png"

# cim, es tengelyek
set title "Mechanikai energia változás"

set autoscale
set key top left

set xlabel "t [s*1000]"
set ylabel "E_{mech} [J]"

# kimenet igazitasa
plot "out.txt" every 10 using 1:2 w l lw 2 lc rgb"green" title "Mechanikai energia változása"

unset output
