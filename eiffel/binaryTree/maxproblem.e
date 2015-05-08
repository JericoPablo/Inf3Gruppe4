class
	MAXPROBLEM

inherit
	DIVISIBLEPROBLEM

create
	make

feature

	solution: MAXSOLUTION

	tree: BINARYTREE assign set_tree

	current_node: NODE

	set_tree (t: BINARYTREE)
		do
			if t.root /= Void then
				tree := t
				current_node := tree.get_root
				solve
			end
		end

	make
		do
			create solution
			create current_node.make (0)
			create tree.make (0)
		end


	is_directly_solvable
		do
			if current_node.right = Void then
				solution.val := current_node.value
				directly_solvable := True
			end
		end

	part
		do
			from

			until
				current_node.right = Void
			loop
				current_node := current_node.get_right
			end
		end

	get_solution: INTEGER_32
		do
			Result := solution.val
		end

end
