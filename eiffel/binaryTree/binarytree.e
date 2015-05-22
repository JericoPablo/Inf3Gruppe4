class
	BINARYTREE

create
	make

feature

	root: detachable NODE assign set_root

	make (val: INTEGER_32)
			--Constructor creates the first value to a root
		do
			create root.make (val)
			output := ""
		end --make

	print_node (n: detachable NODE)
			--print_node is a function to print out in the testingclass
		do
			if attached n as tmp then
				io.put_string (tmp.value.out)
			end
		end --print_node

	insert (val: INTEGER_32)
			--insert calls the insert_recursion and gives the value parameter
		do
			if root /= Void then
				insert_recursion (val, get_root)
			else
				create root.make (val)
			end
		end --insert

	insert_recursion (val: INTEGER_32; n: detachable NODE)
			--insert_recursion creates a new Node into the binarytree and lookup where he have to be placed
		local
			new_node: NODE
		do
			if attached n as n_tmp then
				if val >= n_tmp.value then
					if n_tmp.right = Void then
						create new_node.make (val)
						n_tmp.right := new_node
						new_node.parent := n_tmp
					else
						insert_recursion (val, n_tmp.right)
					end
				end
				if val < n_tmp.value then
					if n_tmp.left = Void then
						create new_node.make (val)
						n_tmp.left := new_node
						new_node.parent := n_tmp
					else
						insert_recursion (val, n_tmp.left)
					end
				end
			end
		end --insert_recursion

	has (val: INTEGER_32): BOOLEAN
			--has calls has_recursion to proof if the value is located in the binarytree
		do
			if root /= void then
				has_recursion (val, get_root)
				Result := has_bool
			else
				Result := False
			end
		end --has

	has_recursion (val: INTEGER_32; n: detachable NODE)
			--has_recursion proofs with the given value and the binarytree nodes on true or false
		do
			if attached n as n_tmp then
				if val = n_tmp.value then
					has_bool := True
				else
					if val > n_tmp.value and n_tmp.right /= Void then
						has_recursion (val, n_tmp.right)
					else
						if val < n_tmp.value and n_tmp.left /= Void then
							has_recursion (val, n_tmp.left)
						else
							has_bool := False
						end
					end
				end
			end
		end --has_recursion

	delete (val: INTEGER_32)
			--delete calls delete_recursion with inputparameter value to delete a node from binarytree
		do
			if root /= Void then
				delete_recursion (val, get_root)
				if has (val) then
					delete (val)
				end
			end
		end --delete

	delete_recursion (val: INTEGER_32; n: detachable NODE)
			--delete_recursion lookup for the node to delete, it shows in which case he have to delete(root, delNoChild)
		do
			if attached n as n_tmp then
				if val = n_tmp.value and n_tmp.left = Void and n_tmp.right = Void and n_tmp.parent /= Void then
					del_no_child (n_tmp)
				else
					if val = n_tmp.value and n_tmp.left = Void and n_tmp.right /= Void and n_tmp.parent /= Void then
						del_one_child (n_tmp, True)
					else
						if val = n_tmp.value and n_tmp.left /= Void and n_tmp.right = Void and n_tmp.parent /= Void then
							del_one_child (n_tmp, False)
						else
							if val = n_tmp.value and n_tmp.left /= Void and n_tmp.right /= Void then
								del_two_children (n_tmp)
							else
								if val = n_tmp.value and n_tmp = root then
									if n_tmp.left = Void and n_tmp.right = Void then
										root := Void
									else
										if n_tmp.left /= Void and n_tmp.right = Void then
											n_tmp.get_left.set_parent (Void)
											root := n_tmp.left
										else
											if n_tmp.left = Void and n_tmp.right /= Void then
												n_tmp.get_right.set_parent (Void)
												root := n_tmp.right
											end
										end
									end
								end
							end
						end
					end
				end
				if val < n_tmp.value then
					delete_recursion (val, n_tmp.left)
				else
					if val > n_tmp.value then
						delete_recursion (val, n_tmp.right)
					end
				end
			end
		end --delete_recursion

	del_no_child (n: NODE)
			--delete a leaf of the binarytree
		do
			if n = n.get_parent.get_left then
				n.get_parent.left := Void
				n.parent := Void
			else
				n.get_parent.right := Void
				n.parent := Void
			end
		end --delNoChild

	del_one_child (n: NODE; has_right: BOOLEAN)
		do
			if has_right then
				if n.get_parent.right = n then
					n.get_right.parent := n.get_parent
					n.get_parent.right := n.right
				else
					n.get_right.parent := n.get_parent
					n.get_parent.left := n.right
				end
			else
				if n.get_parent.right = n then
					n.get_left.parent := n.get_parent
					n.get_parent.right := n.left
				else
					n.get_left.parent := n.get_parent
					n.get_parent.left := n.left
				end
			end
		end

	del_two_children (n: NODE)
		local
			n_smallest: NODE
		do
			n_smallest := get_smallest (n.get_right)
			n.value := n_smallest.value
			if n_smallest.left = Void and n_smallest.right /= Void then
				del_one_child (n_smallest, True)
			else
				del_no_child (n_smallest)
			end
		end

	get_smallest (n: NODE): NODE
		do
			if n.left /= Void then
				Result := get_smallest (n.get_left)
			else
				Result := n
			end

		end

	inorder_output
			--inorder_output calls inorder_recursion
		do
			if root /= Void then
				inorder_recursion (get_root)
				io.put_string (output)
				output := ""
			end
		end --inorder

	preorder_output
			--preorder_output calls preorder_recursion
		do
			if root /= Void then
				preorder_recursion (get_root)
				io.put_string (output)
				output := ""
			end
		end --preorder

	postorder_output
			--postorder_output calls postorder_recursion
		do
			if root /= Void then
				postorder_recursion (get_root)
				io.put_string (output)
				output := ""
			end
		end --postorder

	get_root: NODE
			--returns value of the root
		do
			check attached root as r then
				Result := r
			end
		end --get_root

feature {NONE}

		--Attributes

	has_bool: BOOLEAN

	output: STRING_8

	set_root (r: detachable NODE)
			--Setter for the root of the binarytree
		do
			if attached root as ro then
				root := ro
			end
		end --set_root

	inorder_recursion (n: NODE)
			--order of output is leftside, root, rightside of binarytree
		do
			if n.left /= Void then
				inorder_recursion (n.get_left)
			end
			output := output + n.value.out + " "
			if n.right /= Void then
				inorder_recursion (n.get_right)
			end
		end --inorder_recursion

	preorder_recursion (n: NODE)
			--order of output is root, leftside, rightside of binarytree
		do
			output := output + n.value.out + " "
			if n.left /= Void then
				preorder_recursion (n.get_left)
			end
			if n.right /= Void then
				preorder_recursion (n.get_right)
			end
		end --preorder_recursion

	postorder_recursion (n: NODE)
			--order of output is leftside, rightside, root of binarytree
		do
			if n.left /= Void then
				postorder_recursion (n.get_left)
			end
			if n.right /= Void then
				postorder_recursion (n.get_right)
			end
			output := output + n.value.out + " "
		end -- postorder_recursion

end --class BINARYTREE
