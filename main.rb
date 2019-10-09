#! /usr/bin/env ruby

str = gets().chop()
nums = str.split(' ').map{|i| i.to_i() }

sum = nums.sum()
variant = nums.map{|i| i * i}.sum() / nums.length
avg = sum / nums.length
sd = Math.sqrt(variant - (avg*avg))
hensachis = nums.map{|i| (i - avg) * 10 / sd + 50}

print "Average:", avg, " SD:", sd, " SUM:", sum, "\n"

data = nums.zip(hensachis)
data.sort!{|a, b| a[0] <=> b[0]}.reverse!
print "Score\t|Hensachi\n"
data.each{|i| print i[0], "\t|", i[1], "\n" }