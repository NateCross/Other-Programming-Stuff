-- Global stuff, even functions, I guess, must be in capital letters
-- Otherwise, append 'local' to the start of the line
local function fact (number)
  if number == 0 then
    return 1
  else
    return number * fact(number - 1)
  end
end

print("Enter a number: ")
local input = io.read("*n")    -- Reads a number
print(fact(input))

