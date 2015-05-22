class
	NODE

create
	make

feature

	--Attributes
	left: detachable NODE assign set_left

	right: detachable NODE assign set_right

	parent: detachable NODE assign set_parent

	value: INTEGER_32 assign set_value

	make (val: INTEGER_32)
	--Constructor
		require
			value_is_not_void: val/=Void
		do
			value := val
			ensure
				new_value: value= val
		end--make

	set_left (l: detachable NODE)
	--set the left Node
		require
			left_is_not_void: l/=Void
		do
			left := l
			ensure
				new_left: left= l
		end--set_left

	get_left: NODE
	--returns the value of the left Node
	require
		left_is_not_void: get_left/=Void
		do
			check attached left as l then
				Result := l
			end
			ensure
				acceptable_left: get_left = old left
		end--get_left

	set_right (r: detachable NODE)
	--set the right Node
		require
			right_is_not_void: r/=Void
		do
			right := r
			ensure
				new_right: right=r
		end--set_right

	get_right: NODE
	--returns the value of the right Node
	require
		right_is_not_void: get_right/=Void
		do
			check attached right as r then
				Result := r
			end
			ensure
				acceptable_right: get_right = old right
		end--set right

	set_parent (p: detachable NODE)
	--set the parent of the Node
		require
			parent_is_not_void: p/= Void
		do
			parent := p
			ensure
				new_parent: parent= p
		end--set_parent

	get_parent: NODE
	--returns the value of the Node
	require
		parent_is_not_void: get_parent/=Void
		do
			check attached parent as p then
				Result := p
			end
			ensure
				acceptable_parent: get_parent = old parent
		end--get_parent

	set_value (val: INTEGER_32)
	--sets the value of the given parameter value
		require
			value_not_void : val/= Void
		do
			value := val
			ensure
				new_value: value = val
		end--set_value

end--class NODE
