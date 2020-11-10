package ds

type Node struct {
	Value int
	Next  *Node
}

var size = 0
var stack = new(Node)

func Push(v int) bool {
	if stack == nil {
		stack = &Node{v, nil}
		size = 1
		return true
	}

	temp := &Node{v, nil}
	temp.Next = stack
	stack = temp
	size++
	return true
}

func Pop(t *Node) (int, bool) {
	if size == 0 {
		return 0, false
	}

	if size == 1 {
		size = 0
		stack = nil
		return t.Value, true
	}

	stack = stack.Next
	size--
	return t.Value, true
}
