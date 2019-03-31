set datafile missing '-'
set style data histogram
set terminal png size 800,600 enhanced
set title "Tokens por linea de código" 
set boxwidth 0.5
set style fill solid
set output 'histogram2.png'
plot "data.dat" using 1:3:xtic(2) with boxes
