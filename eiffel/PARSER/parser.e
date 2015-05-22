note
	description : "PARSER application root class"
	date        : "$Date$"
	revision    : "$Revision$"

class
	PARSER


create
	make

feature {NONE}
	make(s:STRING)
		local
			i:INTEGER
			bracketCheck:INTEGER
		do
			bracketCheck:=0
			from i:=1
			until i>s.count
			loop
				if s.item(i).item = ' ' then			--removes the empty positions
					s.remove (i)
				end
				i:=i+1
			end
			from i:=1
			until i>s.count
			loop
				if s.item(i).item = '(' then
					bracketCheck:=bracketCheck+1
				end
				if s.item(i).item = ')' then
					bracketCheck:=bracketCheck-1
				end
				i:=i+1
			end
			if bracketcheck /=0 then
				print("Equasion is not parsable please check all brackets!")
			end
			print(parseEquasion(s))
		end

feature
	solution:DOUBLE
	solutionArray : detachable ARRAY[INTEGER]
	operator : detachable ARRAY[STRING]

feature

	--If '=' is in the equasion the parseExpression gets called with left side and right side after comparing the result is printed
	--Else print the result of  parseExpression wich gets called with the whole equasion
	parseEquasion(s : STRING) : INTEGER
	local
		i:INTEGER
		isEquasion:BOOLEAN
		splitPos:INTEGER
		resLeft,resRight :DOUBLE
	do
		from i:=1
		until i>s.count
		loop
				if s.item(i).item = '=' then
					isEquasion:=TRUE
					splitPos:=i
				end
				i:=i+1
		end
		if(isequasion) then
			resLeft := parseExpression(s.substring (1, splitpos-1))
			resRight := parseExpression(s.substring ( splitpos+1, s.count))
			if resLeft = resRight then
				print("Left side equals right side")
				else
				print("Left side does not equal right side")
			end
		else
			Result:=parseexpression (s)

		end
	end

	parseExpression(s:STRING):INTEGER
	local
		i, j, splitPos, bracketcounter, bracketOpensplit, bracketClosesplit:INTEGER
	do
		create operator.make_filled("",1,50)
			   solutionarray.make_filled("",1,50)
		from i:=1
		until i>s.count
		loop

			if s.item(i).item = '(' then							--searches for the first bracket pair
				bracketopensplit:=s.item(i+1).item
				bracketcounter:=bracketcounter+1
				from j:=1
				until j>s.count
				loop												--searches for the 'deepest' bracket pair
					if s.item(i).item = '(' then
						bracketcounter:=bracketcounter+1
					els if s.item(i).item = ')' then
						bracketcounter:=bracketcounter-1
					 end
					 if bracketcounter=0 then
					 		bracketclosesplit:=j-1
					 end
					j:=j+1
				end --j loop
				solutionArray.fill_with(parseexpression (s.substring (bracketopensplit, bracketclosesplit )))		--saves the sub-expression in the solutionArray (stringarray)
			end 																									--recursive call to save every expression till the last bracket pair
			if s.item(i).item = '+' then
					operator.fill_with(s.item(i).item)
				els if s.item(i).item = '*'  then
					operator.fill_with(s.item(i).item)																--save the operators for calculation in method calc()
				end
			end

			i:=i+1
		end -- i loop
		Result := calc()
	end

	--calculates the equasion
	calc():INTEGER
	local
		i:INTEGER
		res:DOUBLE
		digitPos:INTEGER
	do
		digitpos:=solutionarray.count
		from i:= operator.item(i).item					--backwards throught loop
		until i>=0
		loop
			if operator.item(i).item = '+' then			--adds the latest saved digits together and temporary saves it again in the solutionarray
				res:=solutionarray.item(digitpos).item + solutionarray.item(digitpos-1).item,
				solutionarray.remove(digitpos)
				solutionarray.remove(digitpos-1)
				solutionarray.add_last(res)
			end
			if operator.item(i).item = '*' then			--multiplies the latest saved digits together and temporary saves it again in the solutionarray
				res:=solutionarray.item(digitpos).item * solutionarray.item(digitpos-1).item,
				solutionarray.remove(digitpos)
				solutionarray.remove(digitpos-1)
				solutionarray.add_last(res)
			end

			i:=i-1
		end
		Result:=res
	end


	--Checks if the input is an valid number for calculation ; valid numbers are 1;2;3;4;5;6;7;8;9
	isDigitWithoutZero(i :INTEGER ) : BOOLEAN
	local
		isLegit:BOOLEAN
	do
		islegit:=TRUE
		if isDigit(in) then
			islegit:=FALSE
		end
		RESULT :=islegit
	end

	--Checks if the input is zero
	isDigit(i : integer) : BOOLEAN
	local
		isLegit:BOOLEAN
	do
		islegit:=FALSE
		if in=0 then
			islegit:=TRUE
		end
		Result:=islegit
	end
end
