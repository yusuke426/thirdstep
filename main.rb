#! /usr/bin/env ruby

str = gets().chop()
nums = str.split(' ').map{|i| i.to_i() }

sum = 0
nijo= 0
nums.each {|i|
  sum = sum + i
  nijo = nijo + (i * i)
}
avg = sum / nums.length
print "Average:", avg, " SD:", Math.sqrt((nijo/nums.length) - (avg*avg)), " SUM:", sum, "\n"
