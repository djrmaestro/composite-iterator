package headfirst.composite.menuiterator;

 
import java.util.*;
  
public class CompositeIterator implements Iterator {
	Stack iters_stack = new Stack();
   
	public CompositeIterator(Iterator iterator) {
		iters_stack.push(iterator);
	}
   
	public Object next() {
		if (hasNext()) {
			Iterator iterator = (Iterator) iters_stack.peek();
			MenuComponent component = (MenuComponent) iterator.next();
			if (component instanceof Menu) {
				iters_stack.push(component.createIterator());
			} 
			return component;
		} else {
			return null;
		}
	}
  
	public boolean hasNext() {
		if (iters_stack.empty()) {
			return false;
		} else {
			Iterator iterator = (Iterator) iters_stack.peek();
			if (!iterator.hasNext()) {
				iters_stack.pop();
				return hasNext();
			} else {
				return true;
			}
		}
	}
   
	public void remove() {
		throw new UnsupportedOperationException();
	}
}


