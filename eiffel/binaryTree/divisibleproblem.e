deferred class
	DIVISIBLEPROBLEM

inherit
	PROBLEM

feature

	directly_solvable : BOOLEAN assign set_directly_solvable

	set_directly_solvable (d_solvable: BOOLEAN)
		do
			directly_solvable := d_solvable
		end

	is_directly_solvable
		deferred
		end

	part
		deferred
		end

	solve
	 do
	 	from
	 		directly_solvable := False
	 	until
	 		directly_solvable
	 	loop
			is_directly_solvable
			if directly_solvable = False then
				part
			end
	 	end
	 end

end
