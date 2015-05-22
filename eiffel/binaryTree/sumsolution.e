class
	SUMSOLUTION

inherit
	SOLUTION

feature

		val: INTEGER_32 assign set_val

		set_val (new_val: INTEGER_32)
			do
				val := new_val
			end

invariant
	val_valid: val /= Void

end
