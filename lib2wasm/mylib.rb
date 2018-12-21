def nsquare(n)
  puts "Calling nsquare() with args: #{n}"
  n*n
end

def ncube(n)
  puts "Calling ncube() with args: #{n}"
  n*n*n
end

def nfactorial(n)
  puts "Calling nfactorial() with args: #{n}"
  fact = 1
  (1..n).each do |i|
    fact *= i
  end
  fact
end

