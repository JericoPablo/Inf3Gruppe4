class
	SUMPROBLEM

inherit
	DIVISIBLEPROBLEM

create
	make

feature

	solution: SUMSOLUTION

	tree: BINARYTREE assign set_tree

	current_node: NODE

	set_tree (t: BINARYTREE)
		do
			if t.root /= Void then
				tree := t
				current_node := tree.get_root
				solution.val := 0
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
			if current_node.right = Void and current_node.left = Void then
				solution.val := current_node.value
				directly_solvable := True
			end
		end

	part
		do
			sum_recursion (current_node)
			directly_solvable := True
		end

	sum_recursion (n: detachable NODE)
		do
			if n /= Void then
				solution.val := solution.val + n.value
				sum_recursion (n.left)
				sum_recursion (n.right)
			end

		end

	get_solution: INTEGER_32
		do
			Result := solution.val
		end

end
