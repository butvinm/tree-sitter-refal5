/* Automatically generated file. Don't edit! */
#include "refal05rts.h"


R05_DECLARE_ENTRY_FUNCTION(GO)
R05_DEFINE_METAFUNCTION(Mu, "Mu")
R05_DEFINE_METAFUNCTION(Up, "Up")
R05_DEFINE_METAFUNCTION(Evm_met, "Ev-met")
R05_DEFINE_METAFUNCTION(Residue, "Residue")
R05_DEFINE_METAFUNCTION(k3F_, "?")

R05_DEFINE_ENTRY_FUNCTION(GO, "GO") {
  r05_this_is_generated_function();

  do {
    /* s.A: 2 */
    struct r05_node *p[5] = { 0 };
    /* s.A */
    p[0] = arg_begin->next;
    p[1] = arg_end;
    if (! r05_svar_left(p+2, p[0], p[1]))
      continue;
    if (! r05_empty_hole(p[2], p[1]))
      continue;

    r05_reset_allocator();
    r05_alloc_open_call(p+3);
    r05_alloc_function(&r05f_Mu);
    r05_alloc_svar(p+2);
    r05_alloc_close_call(p+4);
    r05_push_stack(p[4]);
    r05_push_stack(p[3]);
    r05_splice_from_freelist(arg_begin);
    r05_splice_to_freelist(arg_begin, arg_end);
    return;
  } while (0);

  r05_recognition_impossible();
}

static struct r05_function *metatable_entries[] = {
  &r05f_GO,
  &r05f_Mu,
  &r05f_Up,
  &r05f_Evm_met,
  &r05f_Residue,
  &r05f_k3F_,
};

static struct r05_metatable metatable = {
  sizeof(metatable_entries) / sizeof(metatable_entries[0]),
  metatable_entries
};


/* End of file */
