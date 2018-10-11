#!/bin/env ruby

puts "enter a number to check if it's a power of 2!"
num = gets.chomp.to_f

# keep dividing by 2 and see what happens
# if it's a power of 2, we will eventually end up at 2
# otherwise, it will be a decimal of some kind
test = num
while true
	if test.floor != test
		puts "#{num} is not a power of 2..."
		break
	end
	if test == 2
		puts "#{num} is a power of 2!"
		break
	end
	test /= 2
end

exit 0
