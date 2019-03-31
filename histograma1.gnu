set key fixed right top vertical Right noreverse noenhanced autotitle nobox
set datafile missing '-'
set style data linespoints
set xtics border in scale 1,0.5 nomirror rotate by -45  autojustify
set xtics  norangelimit 
set xtics   ()
set title "Ocurrencias de Tokens por lineas de codigo" 
DEBUG_TERM_HTIC = 119
DEBUG_TERM_VTIC = 119
set terminal png size 800,600 enhanced
set output 'histogram1.png'
## Last datafile plotted: "immigration.dat"
plot 'datafile.dat' using 2:xtic(1) title columnheader(2), for [i=3:22] '' using i title columnheader(i)