set terminal pngcairo size 800,600
set output 'stack_plot.png'

set title 'Stack Performance Comparison'
set xlabel 'Test Size'
set ylabel 'Time (µs)'
set grid
set key outside
set datafile separator ','

set logscale y

plot 'stack_data.csv' using 1:2 with linespoints title 'Stack', \
     'stack_data.csv' using 1:3 with linespoints title 'StackFromQueue'

