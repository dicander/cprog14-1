fn main() {
    let a = 1;
    // a += 1;
    // error[E0384]: cannot assign twice to immutable variable `a`
    // C++: const int * b = new int(2); but in Rust this becomes
    //let mut b = Box::new(2);
    // Now, is b a pointer or a reference?
    // b is a pointer, but it is a smart pointer, so it is a reference
    //b += 1;
    // error[E0369]: binary operation `+=` cannot be applied to type `std::boxed::Box<i32>`
    // C++: *b += 1;
    // But if we actually want a pointer here, same as the c++ example on line 5, we can do
    //let c = &mut *b;
    // Now let us combine the box creation on line 6 with the pointer creation on line 13
    // Create a c pointer to the boxed const value 2
    let c = &mut *Box::new(2);
    *c += 1;
    *c -= 1;
    println!("{}", c);
    // Try to reasign c to the boxed value 3:
    //c = &mut *Box::new(3);
    // cannot assign twice to immutable variable `c`
}
