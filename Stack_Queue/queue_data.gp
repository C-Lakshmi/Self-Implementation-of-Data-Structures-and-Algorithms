set terminal pngcairo size 800,600
set output 'queue_plot.png'

set title 'Queue Performance Comparison'
set xlabel 'Test Size'
set ylabel 'Time (µs)'
set grid
set key outside
set datafile separator ','

# Set logarithmic scale for better visibility if the range is large
set logscale y

plot 'queue_data.csv' using 1:2 with linespoints title 'Queue', \
     'queue_data.csv' using 1:3 with linespoints title 'QueueFromStack'

