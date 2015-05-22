class
	TESTING

create
	make

feature {NONE}
	--creates a new Binarytree
	b: BINARYTREE
	mp: MAXPROBLEM
	sp: SUMPROBLEM

	make

		do
			--creates the root
			create b.make (5)
			--insert Nodes
			b.insert (10)
			b.insert (1)
			b.insert (11)
			b.insert (9)
			b.insert (5)
			b.insert (5)
			--inorder_output
			io.put_string ("Inorder: ")
			b.inorder_output
			--new_line
			io.new_line
			--delete Node
			b.delete (5)
			--inorder_output
			io.put_string ("Inorder: ")
			b.inorder_output
			--delete Node
			b.delete (5)
			--new_line
			io.new_line
			--preorder_output
			io.put_string ("Preorder: ")
			b.preorder_output
			--new_line
			io.new_line
			--postorder_output
			io.put_string ("Postorder: ")
			b.postorder_output
			io.new_line

			create mp.make
			mp.set_tree (b)
			io.put_string ("Max: " + mp.get_solution.out)
			io.new_line
			create sp.make
			sp.set_tree (b)
			sp.set_tree (b)
			io.put_string ("Sum: " + sp.get_solution.out)
		end

end--class TESTING
