/* Automatically generated file. Don't edit! */
#include "refal05rts.h"


R05_DECLARE_ENTRY_FUNCTION(ArgList)
R05_DECLARE_ENTRY_FUNCTION(Parse)
R05_DECLARE_ENTRY_FUNCTION(Scan)
R05_DECLARE_ENTRY_FUNCTION(GO)
R05_DECLARE_LOCAL_FUNCTION(GO0)
R05_DECLARE_LOCAL_FUNCTION(GO0u_check)
R05_DECLARE_LOCAL_FUNCTION(GO0u_cont)
R05_DECLARE_LOCAL_FUNCTION(GO1)
R05_DEFINE_LOCAL_ENUM(Success, "Success")
R05_DEFINE_LOCAL_ENUM(Fails, "Fails")
R05_DECLARE_ENTRY_FUNCTION(Prout)

/*
*$FROM LibraryEx
*/
/*
*$FROM R5FW-Parser
*/
R05_DEFINE_ENTRY_FUNCTION(GO, "GO") {
  r05_this_is_generated_function();

  do {
    struct r05_node *p[6] = { 0 };
    /*  */
    p[0] = arg_begin->next;
    p[1] = arg_end;
    if (! r05_empty_hole(p[0], p[1]))
      continue;

    r05_reset_allocator();
    r05_alloc_open_call(p+2);
    r05_alloc_function(&r05f_GO0);
    r05_alloc_open_call(p+3);
    r05_alloc_function(&r05f_ArgList);
    r05_alloc_close_call(p+4);
    r05_alloc_close_call(p+5);
    r05_push_stack(p[5]);
    r05_push_stack(p[2]);
    r05_push_stack(p[4]);
    r05_push_stack(p[3]);
    r05_splice_from_freelist(arg_begin);
    r05_splice_to_freelist(arg_begin, arg_end);
    return;
  } while (0);

  r05_recognition_impossible();
}

R05_DEFINE_LOCAL_FUNCTION(GO0, "GO0") {
  r05_this_is_generated_function();

  do {
    /* e.ProgName: 6 */
    /* e.FilePath: 8 */
    struct r05_node *p[20] = { 0 };
    /* (e.ProgName) (e.FilePath) */
    p[0] = arg_begin->next;
    p[1] = arg_end;
    if (! r05_brackets_left(p+2, p[0], p[1]))
      continue;
    if (! r05_brackets_left(p+4, p[3], p[1]))
      continue;
    if (! r05_empty_hole(p[5], p[1]))
      continue;
    r05_close_evar(p+6, p[2], p[3]);
    r05_close_evar(p+8, p[4], p[5]);

    r05_reset_allocator();
    r05_alloc_open_call(p+10);
    r05_alloc_function(&r05f_GO0u_check);
    r05_alloc_open_bracket(p+11);
    r05_alloc_insert_pos(p+12);
    r05_alloc_close_bracket(p+13);
    r05_alloc_open_bracket(p+14);
    r05_alloc_insert_pos(p+15);
    r05_alloc_close_bracket(p+16);
    r05_alloc_open_call(p+17);
    r05_alloc_function(&r05f_Scan);
    r05_alloc_evar(p+8);
    r05_alloc_close_call(p+18);
    r05_alloc_close_call(p+19);
    r05_push_stack(p[19]);
    r05_push_stack(p[10]);
    r05_push_stack(p[18]);
    r05_push_stack(p[17]);
    r05_link_brackets(p[14], p[16]);
    r05_correct_evar(p+8);
    r05_link_brackets(p[11], p[13]);
    r05_correct_evar(p+6);
    r05_splice_evar(p[12], p+6);
    r05_splice_evar(p[15], p+8);
    r05_splice_from_freelist(arg_begin);
    r05_splice_to_freelist(arg_begin, arg_end);
    return;
  } while (0);

  do {
    /* e.Other: 2 */
    struct r05_node *p[7] = { 0 };
    /* e.Other */
    p[0] = arg_begin->next;
    p[1] = arg_end;
    r05_close_evar(p+2, p[0], p[1]);

    r05_reset_allocator();
    r05_alloc_open_call(p+4);
    r05_alloc_function(&r05f_GO0u_cont);
    r05_alloc_insert_pos(p+5);
    r05_alloc_close_call(p+6);
    r05_push_stack(p[6]);
    r05_push_stack(p[4]);
    r05_correct_evar(p+2);
    r05_splice_evar(p[5], p+2);
    r05_splice_from_freelist(arg_begin);
    r05_splice_to_freelist(arg_begin, arg_end);
    return;
  } while (0);
}

R05_DEFINE_LOCAL_FUNCTION(GO0u_check, "GO0_check") {
  r05_this_is_generated_function();

  do {
    /* e.ProgName: 6 */
    /* e.FilePath: 8 */
    /* e.Tokens: 10 */
    struct r05_node *p[25] = { 0 };
    /* (e.ProgName) (e.FilePath) e.Tokens */
    p[0] = arg_begin->next;
    p[1] = arg_end;
    if (! r05_brackets_left(p+2, p[0], p[1]))
      continue;
    if (! r05_brackets_left(p+4, p[3], p[1]))
      continue;
    r05_close_evar(p+6, p[2], p[3]);
    r05_close_evar(p+8, p[4], p[5]);
    r05_close_evar(p+10, p[5], p[1]);

    r05_reset_allocator();
    r05_alloc_open_call(p+12);
    r05_alloc_function(&r05f_GO1);
    r05_alloc_open_bracket(p+13);
    r05_alloc_insert_pos(p+14);
    r05_alloc_close_bracket(p+15);
    r05_alloc_open_bracket(p+16);
    r05_alloc_insert_pos(p+17);
    r05_alloc_close_bracket(p+18);
    r05_alloc_open_bracket(p+19);
    r05_alloc_insert_pos(p+20);
    r05_alloc_close_bracket(p+21);
    r05_alloc_open_call(p+22);
    r05_alloc_function(&r05f_Parse);
    r05_alloc_evar(p+10);
    r05_alloc_close_call(p+23);
    r05_alloc_close_call(p+24);
    r05_push_stack(p[24]);
    r05_push_stack(p[12]);
    r05_push_stack(p[23]);
    r05_push_stack(p[22]);
    r05_link_brackets(p[19], p[21]);
    r05_correct_evar(p+10);
    r05_link_brackets(p[16], p[18]);
    r05_correct_evar(p+8);
    r05_link_brackets(p[13], p[15]);
    r05_correct_evar(p+6);
    r05_splice_evar(p[14], p+6);
    r05_splice_evar(p[17], p+8);
    r05_splice_evar(p[20], p+10);
    r05_splice_from_freelist(arg_begin);
    r05_splice_to_freelist(arg_begin, arg_end);
    return;
  } while (0);

  do {
    /* e.ProgName: 6 */
    /* e.FilePath: 8 */
    /* e.Other: 10 */
    struct r05_node *p[20] = { 0 };
    /* (e.ProgName) (e.FilePath) e.Other */
    p[0] = arg_begin->next;
    p[1] = arg_end;
    if (! r05_brackets_left(p+2, p[0], p[1]))
      continue;
    if (! r05_brackets_left(p+4, p[3], p[1]))
      continue;
    r05_close_evar(p+6, p[2], p[3]);
    r05_close_evar(p+8, p[4], p[5]);
    r05_close_evar(p+10, p[5], p[1]);

    r05_reset_allocator();
    r05_alloc_open_call(p+12);
    r05_alloc_function(&r05f_GO0u_cont);
    r05_alloc_open_bracket(p+13);
    r05_alloc_insert_pos(p+14);
    r05_alloc_close_bracket(p+15);
    r05_alloc_open_bracket(p+16);
    r05_alloc_insert_pos(p+17);
    r05_alloc_close_bracket(p+18);
    r05_alloc_close_call(p+19);
    r05_push_stack(p[19]);
    r05_push_stack(p[12]);
    r05_link_brackets(p[16], p[18]);
    r05_correct_evar(p+8);
    r05_link_brackets(p[13], p[15]);
    r05_correct_evar(p+6);
    r05_splice_evar(p[14], p+6);
    r05_splice_evar(p[17], p+8);
    r05_splice_from_freelist(arg_begin);
    r05_splice_to_freelist(arg_begin, arg_end);
    return;
  } while (0);

  r05_recognition_impossible();
}

R05_DEFINE_LOCAL_FUNCTION(GO0u_cont, "GO0_cont") {
  r05_this_is_generated_function();

  do {
    /* e.ProgName: 4 */
    /* e.BadArgs: 6 */
    struct r05_node *p[11] = { 0 };
    /* (e.ProgName) e.BadArgs */
    p[0] = arg_begin->next;
    p[1] = arg_end;
    if (! r05_brackets_left(p+2, p[0], p[1]))
      continue;
    r05_close_evar(p+4, p[2], p[3]);
    r05_close_evar(p+6, p[3], p[1]);

    r05_reset_allocator();
    r05_alloc_open_call(p+8);
    r05_alloc_function(&r05f_Prout);
    r05_alloc_chars("Bad args\nUsage: ", 16);
    r05_alloc_insert_pos(p+9);
    r05_alloc_chars(" file_path", 10);
    r05_alloc_close_call(p+10);
    r05_push_stack(p[10]);
    r05_push_stack(p[8]);
    r05_correct_evar(p+4);
    r05_splice_evar(p[9], p+4);
    r05_splice_from_freelist(arg_begin);
    r05_splice_to_freelist(arg_begin, arg_end);
    return;
  } while (0);

  r05_recognition_impossible();
}

R05_DEFINE_LOCAL_FUNCTION(GO1, "GO1") {
  r05_this_is_generated_function();

  do {
    /* e.ProgName: 9 */
    /* e.FilePath: 11 */
    /* e.Tokens: 13 */
    /* e.AST: 15 */
    struct r05_node *p[20] = { 0 };
    /* (e.ProgName) (e.FilePath) (e.Tokens) Success e.AST */
    p[0] = arg_begin->next;
    p[1] = arg_end;
    if (! r05_brackets_left(p+2, p[0], p[1]))
      continue;
    if (! r05_brackets_left(p+4, p[3], p[1]))
      continue;
    if (! r05_brackets_left(p+6, p[5], p[1]))
      continue;
    if (! r05_function_left(p+8, p[7], p[1], &r05f_Success))
      continue;
    r05_close_evar(p+9, p[2], p[3]);
    r05_close_evar(p+11, p[4], p[5]);
    r05_close_evar(p+13, p[6], p[7]);
    r05_close_evar(p+15, p[8], p[1]);

    r05_reset_allocator();
    r05_alloc_open_call(p+17);
    r05_alloc_function(&r05f_Prout);
    r05_alloc_insert_pos(p+18);
    r05_alloc_close_call(p+19);
    r05_push_stack(p[19]);
    r05_push_stack(p[17]);
    r05_correct_evar(p+15);
    r05_splice_evar(p[18], p+15);
    r05_splice_from_freelist(arg_begin);
    r05_splice_to_freelist(arg_begin, arg_end);
    return;
  } while (0);

  do {
    /* e.ProgName: 9 */
    /* e.FilePath: 11 */
    /* e.Tokens: 13 */
    /* e.Errors: 15 */
    struct r05_node *p[20] = { 0 };
    /* (e.ProgName) (e.FilePath) (e.Tokens) Fails e.Errors */
    p[0] = arg_begin->next;
    p[1] = arg_end;
    if (! r05_brackets_left(p+2, p[0], p[1]))
      continue;
    if (! r05_brackets_left(p+4, p[3], p[1]))
      continue;
    if (! r05_brackets_left(p+6, p[5], p[1]))
      continue;
    if (! r05_function_left(p+8, p[7], p[1], &r05f_Fails))
      continue;
    r05_close_evar(p+9, p[2], p[3]);
    r05_close_evar(p+11, p[4], p[5]);
    r05_close_evar(p+13, p[6], p[7]);
    r05_close_evar(p+15, p[8], p[1]);

    r05_reset_allocator();
    r05_alloc_open_call(p+17);
    r05_alloc_function(&r05f_Prout);
    r05_alloc_chars("Failed to parse file:\n", 22);
    r05_alloc_insert_pos(p+18);
    r05_alloc_close_call(p+19);
    r05_push_stack(p[19]);
    r05_push_stack(p[17]);
    r05_correct_evar(p+15);
    r05_splice_evar(p[18], p+15);
    r05_splice_from_freelist(arg_begin);
    r05_splice_to_freelist(arg_begin, arg_end);
    return;
  } while (0);

  r05_recognition_impossible();
}


/* End of file */
