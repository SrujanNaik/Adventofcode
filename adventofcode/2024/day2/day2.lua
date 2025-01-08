function check_condation(row)
	local ascending = 0
	local decending = 0

	if(#row < 2) then 
		return 1
	end

	local is_ascending = row[1] - row[2]
	if(is_ascending < 0) then
		for i = 1, #row-1 do
			ascending = 1
			local temp = row[i+1] - row[i]
			if(temp > 3 or temp < 1) then 
				return 0
			end
			if(ascending == 0 or row[i] > row[i+1]) then
				ascending = 0
			end
		end
	elseif(is_ascending > 0) then
		for i = 1, #row-1 do
			decending = 1
			local temp = row[i] - row[i+1]
			if(temp > 3 or temp < 1) then 
				return 0
			end
			if(decending == 0 or row[i] < row[i+1]) then
				decending = 0
			end
		end
	else
		return 0
	end

	if(ascending == 1 or decending == 1) then
		return 1
	end
	return 0
end


local file = io.open("unusual_dataset.txt", "r")
if not file then
	print("Error retriving file")
	return
end

local data = {}

for line in file:lines() do
	local row = {}
	for num in line:gmatch("%d+") do
		table.insert(row, tonumber(num))
	end
	table.insert(data, row)
end

file:close()

local sol = 0
for i, row in ipairs(data) do
	if(check_condation(row)==1) then
		sol = sol + 1
	end
end

print(sol)
