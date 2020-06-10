## Without Arguments

Refactor this code so that instead of having `vec0` and creating the vector in `fn main`, we instead create it within `fn fill_vec` and transfer the freshly created vector from fill_vec to its caller.

<div class="hint">
  Stop reading whenever you feel like you have enough direction :)
  Or try doing one step and then fixing the compiler errors that result!

  So the end goal is to:
  - get rid of the first line in main that creates the new vector
  - so then `vec0` doesn't exist, so we can't pass it to `fill_vec`
  - we don't want to pass anything to `fill_vec`, so its signature should reflect that it does not take any arguments
  - since we're not creating a new vec in `main` anymore, we need to create a new vec in `fill_vec`, similarly to the way we did in `main`
</div>
