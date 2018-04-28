#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __symbol_get");

static int __init __symbol_get_init(void);
static void __exit __symbol_get_exit(void);

static int
__init __symbol_get_init(void)
{
    const char * symbol_name;
    void * addr;

    symbol_name = "init_module";
    addr = __symbol_get(symbol_name);

    if (addr != NULL)
        printk(KERN_INFO "the address of %s is: %lx\n", symbol_name, (unsigned long)addr);
    else
    printk("%s isn't found\n", symbol_name);

    symbol_name = "cleanup_module";
    addr = __symbol_get(symbol_name);

    if (addr != NULL)
        printk(KERN_INFO "the address of %s is: %lx\n", symbol_name, (unsigned long)addr);
    else
    printk("%s isn't found\n", symbol_name);

    return 0;
}

static void
__exit __symbol_get_exit(void)
{
    printk(KERN_INFO "module exit ok !\n");
}

module_init(__symbol_get_init);
module_exit(__symbol_get_exit);


/*

# nm -g /lib/modules/`uname -r`/kernel/fs/ext4/ext4.ko
                 U add_to_page_cache_lru
                 U __alloc_percpu
                 U __alloc_workqueue_key
                 U __bdev_dax_supported
                 U bdevname
                 U __bdevname
                 U bdev_read_only
                 U __bforget
                 U bh_submit_read
                 U bh_uptodate_or_lock
                 U bio_add_page
                 U bio_alloc_bioset
                 U bio_associate_blkcg
                 U bio_put
                 U blkdev_get_by_dev
                 U __blkdev_issue_discard
                 U blkdev_issue_discard
                 U blkdev_issue_flush
                 U blkdev_issue_zeroout
                 U blkdev_put
                 U blk_finish_plug
                 U blk_start_plug
                 U blk_status_to_errno
                 U block_commit_write
                 U __blockdev_direct_IO
                 U blockdev_superblock
                 U block_invalidatepage
                 U block_is_partially_uptodate
                 U block_page_mkwrite
                 U block_read_full_page
                 U __block_write_begin
                 U block_write_end
                 U __breadahead
                 U __bread_gfp
                 U __brelse
                 U buffer_migrate_page
                 U call_rcu_sched
                 U capable
                 U clean_bdev_aliases
0000000000000000 T cleanup_module
                 U clear_inode
                 U clear_nlink
                 U clear_page_dirty_for_io
                 U complete
                 U _cond_resched
                 U congestion_wait
                 U _copy_from_user
                 U _copy_to_user
                 U cpumask_next
                 U cpu_number
                 U __cpu_online_mask
                 U __cpu_possible_mask
                 U crc16
                 U create_empty_buffers
                 U crypto_alloc_shash
                 U crypto_destroy_tfm
                 U crypto_shash_update
                 U current_task
                 U current_time
                 U dax_finish_sync_fault
                 U dax_iomap_fault
                 U dax_iomap_rw
                 U dax_writeback_mapping_range
                 U del_timer_sync
                 U destroy_workqueue
                 U d_find_any_alias
                 U d_instantiate
                 U d_make_root
                 U d_obtain_alias
000000000001d070 T do_journal_get_write_access
                 U down_read
                 U down_read_trylock
                 U down_write
                 U down_write_trylock
                 U d_path
                 U dput
                 U dqget
                 U dqput
                 U dquot_acquire
                 U dquot_alloc
                 U dquot_alloc_inode
                 U __dquot_alloc_space
                 U dquot_claim_space_nodirty
                 U dquot_commit
                 U dquot_commit_info
                 U dquot_destroy
                 U dquot_disable
                 U dquot_drop
                 U dquot_enable
                 U dquot_file_open
                 U dquot_free_inode
                 U __dquot_free_space
                 U dquot_get_dqblk
                 U dquot_get_next_dqblk
                 U dquot_get_next_id
                 U dquot_get_state
                 U dquot_initialize
                 U dquot_initialize_needed
                 U dquot_mark_dquot_dirty
                 U dquot_quotactl_sysfile_ops
                 U dquot_quota_off
                 U dquot_quota_on
                 U dquot_quota_on_mount
                 U dquot_quota_sync
                 U dquot_release
                 U dquot_resume
                 U dquot_set_dqblk
                 U dquot_set_dqinfo
                 U __dquot_transfer
                 U dquot_transfer
                 U dquot_writeback_dquots
                 U drop_nlink
                 U d_splice_alias
                 U d_tmpfile
0000000000030330 T __dump_mmp_msg
                 U dump_stack
0000000000018630 T empty_inline_dir
                 U end_buffer_read_sync
                 U end_buffer_write_sync
                 U end_page_writeback
                 U event_triggers_call
000000000004c760 T __ext4_abort
000000000001d110 T ext4_alloc_da_blocks
000000000004ec20 T ext4_alloc_flex_bg_array
0000000000000980 T ext4_bg_has_super
0000000000000af0 T ext4_bg_num_gdb
0000000000039890 T ext4_bio_write_page
000000000004b7c0 T ext4_block_bitmap
00000000000017f0 T ext4_block_bitmap_csum_set
0000000000001720 T ext4_block_bitmap_csum_verify
000000000004b900 T ext4_block_bitmap_set
000000000001cde0 T ext4_bread
000000000001ce80 T ext4_bread_batch
000000000004f7a0 T ext4_calculate_overhead
00000000000052a0 T ext4_can_extents_be_merged
000000000001d2f0 T ext4_can_truncate
0000000000023a20 T ext4_change_inode_journal_flag
0000000000002d30 T ext4_check_all_de
0000000000001d30 T ext4_check_blockref
00000000000020d0 T __ext4_check_dir_entry
000000000001ea50 T ext4_chunk_trans_blocks
00000000000006e0 T ext4_claim_free_clusters
000000000004eb40 T ext4_clear_inode
000000000000aab0 T ext4_collapse_range
0000000000025e20 T ext4_compat_ioctl
0000000000019090 T ext4_convert_inline_data
000000000000a2f0 T ext4_convert_unwritten_extents
00000000000132f0 T ext4_count_dirs
0000000000001580 T ext4_count_free
00000000000008c0 T ext4_count_free_clusters
0000000000013280 T ext4_count_free_inodes
0000000000019e60 T ext4_da_get_block_prep
0000000000001cb0 T ext4_data_block_valid
000000000001b7f0 T ext4_da_update_reserve_space
00000000000173c0 T ext4_da_write_inline_data_begin
00000000000177e0 T ext4_da_write_inline_data_end
000000000004b9e0 T ext4_decode_error
0000000000018420 T ext4_delete_inline_entry
0000000000018870 T ext4_destroy_inline_data
000000000001c7f0 T ext4_dio_get_block
0000000000032170 T ext4_dirent_csum_verify
0000000000001cc0 R ext4_dir_inode_operations
00000000000000c0 R ext4_dir_operations
00000000000239c0 T ext4_dirty_inode
000000000002c570 T ext4_discard_preallocations
0000000000030c50 T ext4_double_down_write_data_sem
0000000000030c90 T ext4_double_up_write_data_sem
00000000000370c0 T ext4_empty_dir
0000000000003840 R ext4_encrypted_symlink_inode_operations
0000000000010720 T ext4_end_bitmap_read
0000000000039320 T ext4_end_io_rsv_work
000000000004bfe0 T __ext4_error
000000000004c490 T __ext4_error_file
000000000004c100 T __ext4_error_inode
000000000000d630 T ext4_es_cache_extent
000000000000d310 T ext4_es_find_delayed_extent_range
000000000000d2f0 T ext4_es_init_tree
000000000000d4a0 T ext4_es_insert_extent
000000000000d730 T ext4_es_lookup_extent
000000000000db60 T ext4_es_register_shrinker
000000000000d8e0 T ext4_es_remove_extent
000000000000dc80 T ext4_es_unregister_shrinker
0000000000021860 T ext4_evict_inode
000000000000d2d0 T ext4_exit_es
000000000002c510 T ext4_exit_mballoc
0000000000039300 T ext4_exit_pageio
0000000000053cf0 T ext4_exit_sysfs
0000000000001a30 T ext4_exit_system_zone
000000000001f320 T ext4_expand_extra_isize
00000000000585b0 T ext4_expand_extra_isize_ea
0000000000007460 T ext4_ext_calc_credits_for_single_extent
0000000000004a70 T ext4_ext_calc_metadata_amount
0000000000004b30 T ext4_ext_check_inode
0000000000004660 T __ext4_ext_dirty
0000000000004b60 T ext4_ext_drop_refs
00000000000074c0 T ext4_ext_index_trans_blocks
0000000000008760 T ext4_ext_init
0000000000005aa0 T ext4_ext_insert_extent
00000000000094f0 T ext4_ext_map_blocks
000000000002f6e0 T ext4_ext_migrate
0000000000005080 T ext4_ext_next_allocated_block
0000000000004d70 T ext4_ext_precache
0000000000008770 T ext4_ext_release
0000000000007500 T ext4_ext_remove_space
0000000000004d90 T ext4_ext_tree_init
000000000000a260 T ext4_ext_truncate
000000000000b3c0 T ext4_fallocate
00000000000036c0 R ext4_fast_symlink_inode_operations
000000000000a4c0 T ext4_fiemap
000000000001e210 T ext4_file_getattr
0000000000000700 R ext4_file_inode_operations
00000000000240f0 T ext4_filemap_fault
00000000000007c0 R ext4_file_operations
00000000000094c0 T ext4_find_delalloc_cluster
0000000000008780 T ext4_find_delalloc_range
0000000000034be0 T ext4_find_dest_de
0000000000004dd0 T ext4_find_extent
0000000000016890 T ext4_find_inline_data_nolock
00000000000182b0 T ext4_find_inline_entry
0000000000053460 T ext4_force_commit
00000000000032a0 T __ext4_forget
000000000002d580 T ext4_free_blocks
0000000000000c10 T ext4_free_clusters_after_init
000000000004b840 T ext4_free_group_clusters
000000000004b960 T ext4_free_group_clusters_set
00000000000115b0 T ext4_free_inode
000000000004b870 T ext4_free_inodes_count
000000000004b980 T ext4_free_inodes_set
0000000000010230 T ext4fs_dirhash
000000000000f0d0 T ext4_fsmap_from_internal
000000000000f130 T ext4_fsmap_to_internal
0000000000036990 T ext4_generic_delete_entry
0000000000059560 T ext4_get_acl
000000000001e180 T ext4_getattr
000000000001cc50 T ext4_getblk
000000000001c070 T ext4_get_block
000000000001c5b0 T ext4_get_block_unwritten
0000000000018160 T ext4_get_first_inline_block
000000000000fa10 T ext4_getfsmap
000000000000f170 T ext4_getfsmap_find_fixed_metadata
00000000000005a0 T ext4_get_group_desc
0000000000000550 T ext4_get_group_no_and_offset
0000000000000510 T ext4_get_group_number
000000000001d360 T ext4_get_inode_loc
00000000000578a0 T ext4_get_inode_usage
0000000000039800 T ext4_get_io_end
0000000000016720 T ext4_get_max_inline_size
0000000000034b00 T ext4_get_parent
000000000001d480 T ext4_get_projid
000000000001b7e0 T ext4_get_reserved_space
000000000003c9d0 T ext4_group_add
000000000002e030 T ext4_group_add_blocks
000000000004ed60 T ext4_group_desc_csum_set
000000000004ed10 T ext4_group_desc_csum_verify
000000000003d010 T ext4_group_extend
000000000004e6d0 T __ext4_grp_locked_error
0000000000032df0 T ext4_handle_dirty_dirent_node
00000000000034b0 T __ext4_handle_dirty_metadata
0000000000003640 T __ext4_handle_dirty_super
0000000000033990 T ext4_htree_fill_tree
0000000000002c10 T ext4_htree_free_dir_info
0000000000002c30 T ext4_htree_store_dirent
000000000001d4b0 T ext4_iget
000000000001e010 T ext4_iget_normal
0000000000014c90 T ext4_ind_calc_metadata_amount
0000000000014220 T ext4_ind_map_blocks
000000000002fe70 T ext4_ind_migrate
0000000000015040 T ext4_ind_remove_space
0000000000014d20 T ext4_ind_trans_blocks
0000000000014d50 T ext4_ind_truncate
00000000000599c0 T ext4_init_acl
0000000000036bf0 T ext4_init_dot_dotdot
0000000000000031 T ext4_init_es
0000000000013360 T ext4_init_inode_table
00000000000394b0 T ext4_init_io_end
0000000000000062 T ext4_init_mballoc
0000000000000123 T ext4_init_pageio
0000000000059b50 T ext4_init_security
0000000000004932 T ext4_init_sysfs
0000000000000000 T ext4_init_system_zone
00000000000189d0 T ext4_inline_data_fiemap
00000000000188d0 T ext4_inline_data_iomap
0000000000018bd0 T ext4_inline_data_truncate
000000000001d330 T ext4_inode_attach_jinode
000000000004b7e0 T ext4_inode_bitmap
0000000000001670 T ext4_inode_bitmap_csum_set
00000000000015a0 T ext4_inode_bitmap_csum_verify
000000000004b920 T ext4_inode_bitmap_set
000000000001b6d0 T ext4_inode_is_fast_symlink
000000000004b810 T ext4_inode_table
000000000004b940 T ext4_inode_table_set
00000000000014b0 T ext4_inode_to_goal_block
0000000000034d70 T ext4_insert_dentry
000000000000aef0 T ext4_insert_range
0000000000024a40 T ext4_ioctl
0000000000000080 B ext4__ioend_wq
00000000000013b0 R ext4_iomap_ops
0000000000039810 T ext4_io_submit
0000000000039870 T ext4_io_submit_init
000000000001b970 T ext4_issue_zeroout
000000000004b8d0 T ext4_itable_unused_count
000000000004b9c0 T ext4_itable_unused_set
0000000000003450 T __ext4_journal_get_create_access
0000000000003200 T __ext4_journal_get_write_access
00000000000172c0 T ext4_journalled_write_inline_data
00000000000030e0 T __ext4_journal_start_reserved
0000000000002f20 T __ext4_journal_start_sb
0000000000003040 T __ext4_journal_stop
000000000004b740 T ext4_kvmalloc
000000000004b780 T ext4_kvzalloc
0000000000057610 T ext4_listxattr
000000000000dcb0 T ext4_llseek
000000000001b9c0 T ext4_map_blocks
00000000000115a0 T ext4_mark_bitmap_end
000000000001ea60 T ext4_mark_iloc_dirty
000000000001f4d0 T ext4_mark_inode_dirty
000000000002b630 T ext4_mb_add_groupinfo
000000000002b560 T ext4_mb_alloc_groupinfo
000000000002eda0 T ext4_mballoc_query_range
000000000002b840 T ext4_mb_init
000000000002c9d0 T ext4_mb_new_blocks
000000000002bd30 T ext4_mb_release
0000000000030cb0 T ext4_move_extents
0000000000039e50 T ext4_mpage_readpages
000000000004ba80 T __ext4_msg
0000000000030790 T ext4_multi_mount_protect
0000000000011b90 T __ext4_new_inode
00000000000007a0 T ext4_new_meta_blocks
0000000000037330 T ext4_orphan_add
00000000000386a0 T ext4_orphan_del
0000000000012fa0 T ext4_orphan_get
0000000000023c10 T ext4_page_mkwrite
000000000002c0c0 T ext4_process_freed_data
00000000000206b0 T ext4_punch_hole
0000000000039760 T ext4_put_io_end
00000000000394f0 T ext4_put_io_end_defer
0000000000001470 T ext4_read_block_bitmap
0000000000000e70 T ext4_read_block_bitmap_nowait
0000000000017e00 T ext4_read_inline_dir
00000000000169a0 T ext4_readpage_inline
000000000004eda0 T ext4_register_li_request
0000000000053b90 T ext4_register_sysfs
0000000000001a50 T ext4_release_system_zone
000000000001f270 T ext4_reserve_inode_write
000000000003c910 T ext4_resize_begin
000000000003c9b0 T ext4_resize_end
000000000003d240 T ext4_resize_fs
0000000000033c60 T ext4_search_dir
000000000000d980 T ext4_seq_es_shrinker_info_show
0000000000001600 R ext4_seq_mb_groups_fops
000000000004ebd0 T ext4_seq_options_show
00000000000597d0 T ext4_set_acl
000000000001d180 T ext4_set_aops
0000000000023020 T ext4_setattr
0000000000027b20 T ext4_set_bits
000000000001d380 T ext4_set_inode_flags
0000000000001ac0 T ext4_setup_system_zone
0000000000000720 T ext4_should_retry_alloc
0000000000001c00 R ext4_special_inode_operations
000000000004c670 T __ext4_std_error
000000000004b6a0 T ext4_superblock_csum_set
000000000000bcf0 T ext4_swap_extents
0000000000003780 R ext4_symlink_inode_operations
000000000000fd30 T ext4_sync_file
000000000002e4c0 T ext4_trim_fs
0000000000020bd0 T ext4_truncate
000000000001b770 T ext4_truncate_restart_trans
0000000000017890 T ext4_try_add_inline_entry
00000000000181d0 T ext4_try_create_inline_dir
0000000000018b10 T ext4_try_to_evict_inline_data
0000000000016ab0 T ext4_try_to_write_inline_data
0000000000053c80 T ext4_unregister_sysfs
00000000000205e0 T ext4_update_disksize_before_punch
000000000004e930 T ext4_update_dynamic_rev
000000000004b8a0 T ext4_used_dirs_count
000000000004b9a0 T ext4_used_dirs_set
0000000000000640 T ext4_wait_block_bitmap
000000000001cfd0 T ext4_walk_page_buffers
000000000004e240 T __ext4_warning
000000000004e5e0 T __ext4_warning_inode
0000000000017130 T ext4_write_inline_data_end
000000000001e040 T ext4_write_inode
000000000001e290 T ext4_writepage_trans_blocks
00000000000591f0 T ext4_xattr_create_cache
0000000000058e00 T ext4_xattr_delete_inode
0000000000059200 T ext4_xattr_destroy_cache
0000000000057390 T ext4_xattr_get
000000000000a1e0 D ext4_xattr_handlers
0000000000057c70 T ext4_xattr_ibody_find
0000000000057230 T ext4_xattr_ibody_get
0000000000057d30 T ext4_xattr_ibody_inline_set
00000000000591b0 T ext4_xattr_inode_array_free
0000000000003f60 R ext4_xattr_security_handler
0000000000058460 T ext4_xattr_set
0000000000057af0 T __ext4_xattr_set_credits
0000000000058430 T ext4_xattr_set_credits
0000000000057e60 T ext4_xattr_set_handle
0000000000003ee0 R ext4_xattr_trusted_handler
0000000000003f20 R ext4_xattr_user_handler
000000000001d230 T ext4_zero_partial_blocks
                 U __fdget
                 U __fentry__
                 U fiemap_check_flags
                 U fiemap_fill_next_extent
                 U filemap_fault
                 U filemap_flush
                 U filemap_map_pages
                 U __filemap_set_wb_err
                 U filemap_write_and_wait
                 U filemap_write_and_wait_range
                 U file_path
                 U file_remove_privs
                 U file_update_time
                 U file_write_and_wait_range
                 U __find_get_block
                 U find_inode_nowait
                 U find_next_bit
                 U find_next_zero_bit
                 U finish_wait
                 U flush_workqueue
                 U fput
                 U free_pages
                 U free_percpu
                 U freeze_bdev
                 U freezing_slow_path
                 U from_kgid
                 U from_kgid_munged
                 U from_kprojid
                 U from_kuid
                 U from_kuid_munged
                 U fs_bio_set
                 U fscrypt_decrypt_bio_pages
                 U fscrypt_decrypt_page
                 U fscrypt_encrypt_page
                 U fscrypt_file_open
                 U fscrypt_fname_alloc_buffer
                 U fscrypt_fname_disk_to_usr
                 U fscrypt_fname_encrypted_size
                 U fscrypt_fname_free_buffer
                 U fscrypt_fname_usr_to_disk
                 U fscrypt_get_ctx
                 U fscrypt_get_encryption_info
                 U fscrypt_has_permitted_context
                 U fscrypt_inherit_context
                 U fscrypt_ioctl_get_policy
                 U fscrypt_ioctl_set_policy
                 U __fscrypt_prepare_link
                 U __fscrypt_prepare_lookup
                 U __fscrypt_prepare_rename
                 U fscrypt_pullback_bio_page
                 U fscrypt_put_encryption_info
                 U fscrypt_release_ctx
                 U fscrypt_restore_control_page
                 U fscrypt_setup_filename
                 U fscrypt_zeroout_range
                 U fs_dax_get_by_bdev
                 U fs_kobj
                 U fs_overflowgid
                 U fs_overflowuid
                 U generate_random_uuid
                 U generic_block_bmap
                 U generic_block_fiemap
                 U generic_check_addressable
                 U generic_error_remove_page
                 U generic_fh_to_dentry
                 U generic_fh_to_parent
                 U __generic_file_fsync
                 U generic_file_llseek_size
                 U generic_file_read_iter
                 U generic_file_splice_read
                 U __generic_file_write_iter
                 U generic_fillattr
                 U generic_read_dir
                 U generic_write_checks
                 U generic_write_end
                 U get_acl
                 U __getblk_gfp
                 U get_seconds
                 U __get_user_2
                 U __get_user_4
                 U __get_user_8
                 U get_zeroed_page
                 U grab_cache_page_write_begin
0000000000017aa0 T htree_inlinedir_to_tree
                 U I_BDEV
                 U iget_failed
                 U iget_locked
                 U igrab
                 U ihold
                 U inc_nlink
                 U in_group_p
0000000000032130 T initialize_dirent_tail
0000000000004792 T init_module
                 U __init_rwsem
                 U init_special_inode
                 U init_timer_key
                 U init_user_ns
                 U init_uts_ns
                 U init_wait_entry
                 U __init_waitqueue_head
                 U inode_dio_wait
                 U inode_init_once
                 U inode_init_owner
                 U inode_needs_sync
                 U inode_newsize_ok
                 U inode_nohighmem
                 U inode_owner_or_capable
                 U inode_set_flags
                 U insert_inode_locked
                 U invalidate_bdev
                 U invalidate_inode_buffers
                 U iomap_seek_data
                 U iomap_seek_hole
                 U iomap_zero_range
                 U iov_iter_alignment
                 U iput
                 U is_bad_inode
                 U iter_file_splice_write
                 U jbd2_complete_transaction
                 U jbd2_inode_cache
                 U jbd2_journal_abort
                 U jbd2_journal_begin_ordered_truncate
                 U jbd2_journal_blocks_per_page
                 U jbd2_journal_check_available_features
                 U jbd2_journal_clear_err
                 U jbd2_journal_clear_features
                 U jbd2_journal_destroy
                 U jbd2_journal_dirty_metadata
                 U jbd2_journal_errno
                 U jbd2_journal_extend
                 U jbd2_journal_flush
                 U jbd2_journal_force_commit
                 U jbd2_journal_force_commit_nested
                 U jbd2_journal_forget
                 U jbd2_journal_free_reserved
                 U jbd2_journal_get_create_access
                 U jbd2_journal_get_write_access
                 U jbd2_journal_init_dev
                 U jbd2_journal_init_inode
                 U jbd2_journal_init_jbd_inode
                 U jbd2_journal_inode_add_wait
                 U jbd2_journal_inode_add_write
                 U jbd2_journal_invalidatepage
                 U jbd2_journal_load
                 U jbd2_journal_lock_updates
                 U jbd2_journal_release_jbd_inode
                 U jbd2_journal_restart
                 U jbd2_journal_revoke
                 U jbd2_journal_set_features
                 U jbd2__journal_start
                 U jbd2_journal_start_commit
                 U jbd2_journal_start_reserved
                 U jbd2_journal_stop
                 U jbd2_journal_try_to_free_buffers
                 U jbd2_journal_unlock_updates
                 U jbd2_journal_update_sb_errno
                 U jbd2_journal_wipe
                 U jbd2_log_wait_commit
                 U jbd2_transaction_committed
                 U jbd2_trans_will_send_data_barrier
                 U jiffies
                 U kern_path
                 U kfree
                 U kfree_call_rcu
                 U kfree_link
                 U kill_block_super
                 U __kmalloc
                 U kmalloc_caches
                 U kmem_cache_alloc
                 U kmem_cache_alloc_trace
                 U kmem_cache_create
                 U kmem_cache_destroy
                 U kmem_cache_free
                 U kobject_del
                 U kobject_init_and_add
                 U kobject_put
                 U kobject_set_name
                 U kset_register
                 U kset_unregister
                 U kstrdup
                 U kstrndup
                 U kstrtoull
                 U kthread_create_on_node
                 U kthread_should_stop
                 U kthread_stop
                 U ktime_get
                 U ktime_get_real_seconds
                 U kvfree
                 U kvmalloc_node
                 U __list_add_valid
                 U __list_del_entry_valid
                 U list_sort
                 U ll_rw_block
                 U __lock_buffer
                 U __lock_page
                 U lock_two_nondirectories
                 U make_bad_inode
                 U make_kgid
                 U make_kprojid
                 U make_kuid
                 U mapping_tagged
                 U mark_buffer_dirty
                 U mark_buffer_dirty_inode
                 U __mark_inode_dirty
                 U match_int
                 U match_strdup
                 U match_token
                 U mb_cache_create
                 U mb_cache_destroy
                 U mb_cache_entry_create
                 U mb_cache_entry_delete
                 U mb_cache_entry_find_first
                 U mb_cache_entry_find_next
                 U __mb_cache_entry_free
                 U mb_cache_entry_get
                 U mb_cache_entry_touch
                 U memchr_inv
                 U memcmp
                 U memcpy
                 U memmove
                 U memset
                 U memweight
                 U mnt_drop_write_file
                 U mnt_want_write_file
                 U mod_timer
                 U mount_bdev
                 U msleep
                 U __mutex_init
                 U mutex_lock
                 U mutex_unlock
                 U new_inode
                 U noop_backing_dev_info
                 U nr_cpu_ids
                 U pagecache_get_page
                 U pagecache_isize_extended
                 U page_cache_sync_readahead
                 U page_get_link
                 U page_mapped
                 U page_offset_base
                 U __page_symlink
                 U pagevec_lookup_range
                 U pagevec_lookup_range_tag
                 U __pagevec_release
                 U page_zero_new_buffers
                 U panic
                 U path_put
                 U PDE_DATA
                 U percpu_counter_add_batch
                 U percpu_counter_batch
                 U percpu_counter_destroy
                 U __percpu_counter_init
                 U __percpu_counter_sum
                 U __percpu_down_read
                 U percpu_down_write
                 U percpu_free_rwsem
                 U __percpu_init_rwsem
                 U __per_cpu_offset
                 U __percpu_up_read
                 U percpu_up_write
                 U perf_trace_buf_alloc
                 U perf_trace_run_bpf_submit
                 U posix_acl_access_xattr_handler
                 U posix_acl_alloc
                 U posix_acl_chmod
                 U posix_acl_create
                 U posix_acl_default_xattr_handler
                 U posix_acl_update_mode
                 U prandom_u32
                 U prepare_to_wait_event
                 U print_hex_dump
                 U printk
                 U proc_create_data
                 U proc_mkdir
                 U put_dax
                 U __put_page
                 U __put_user_4
                 U pv_irq_ops
                 U pv_lock_ops
                 U queue_work_on
                 U ___ratelimit
                 U _raw_read_lock
                 U _raw_spin_lock
                 U _raw_spin_lock_irqsave
                 U _raw_spin_trylock
                 U _raw_spin_unlock_irqrestore
                 U _raw_write_lock
                 U _raw_write_trylock
                 U rb_erase
                 U rb_first
                 U rb_first_postorder
                 U rb_insert_color
                 U rb_next
                 U rb_next_postorder
                 U rb_prev
                 U rcu_barrier
                 U read_cache_page
                 U redirty_page_for_writepage
                 U __refrigerator
                 U register_filesystem
                 U register_shrinker
                 U remove_proc_entry
                 U __sb_end_write
                 U sb_min_blocksize
                 U sb_set_blocksize
                 U __sb_start_write
                 U schedule
                 U schedule_timeout_interruptible
                 U schedule_timeout_uninterruptible
                 U security_inode_init_security
                 U seq_escape
                 U seq_lseek
                 U seq_open
                 U seq_printf
                 U seq_putc
                 U seq_puts
                 U seq_read
                 U seq_release
                 U setattr_copy
                 U setattr_prepare
                 U set_blocksize
                 U set_cached_acl
                 U set_nlink
                 U __set_page_dirty_buffers
                 U __set_page_dirty_nobuffers
                 U set_task_ioprio
                 U simple_get_link
                 U simple_strtoul
                 U single_open
                 U single_release
                 U skip_spaces
                 U snprintf
                 U sort
                 U __stack_chk_fail
                 U strchr
                 U strcmp
                 U strlcpy
                 U strlen
                 U strncmp
                 U strncpy
                 U strreplace
                 U strsep
                 U submit_bh
                 U submit_bio
                 U submit_bio_wait
                 U sync_blockdev
                 U __sync_dirty_buffer
                 U sync_dirty_buffer
                 U sync_filesystem
                 U sync_inode_metadata
                 U sync_mapping_buffers
                 U system_freezing_cnt
                 U tag_pages_for_writeback
                 U __test_set_page_writeback
                 U thaw_bdev
                 U this_cpu_off
0000000000000000 D __this_module
                 U thp_get_unmapped_area
                 U touch_atime
                 U trace_define_field
                 U trace_event_buffer_commit
                 U trace_event_buffer_reserve
                 U trace_event_ignore_this_pid
                 U trace_event_raw_init
                 U trace_event_reg
                 U trace_handle_return
0000000000001180 D __tracepoint_ext4_allocate_blocks
0000000000001840 D __tracepoint_ext4_allocate_inode
0000000000001040 D __tracepoint_ext4_alloc_da_blocks
0000000000001740 D __tracepoint_ext4_begin_ordered_truncate
0000000000000200 D __tracepoint_ext4_collapse_range
0000000000000e40 D __tracepoint_ext4_da_release_space
0000000000000e80 D __tracepoint_ext4_da_reserve_space
0000000000000ec0 D __tracepoint_ext4_da_update_reserve_space
00000000000016c0 D __tracepoint_ext4_da_write_begin
0000000000001600 D __tracepoint_ext4_da_write_end
0000000000001580 D __tracepoint_ext4_da_write_pages
0000000000001540 D __tracepoint_ext4_da_write_pages_extent
0000000000000d00 D __tracepoint_ext4_direct_IO_enter
0000000000000cc0 D __tracepoint_ext4_direct_IO_exit
0000000000001380 D __tracepoint_ext4_discard_blocks
0000000000001240 D __tracepoint_ext4_discard_preallocations
00000000000017c0 D __tracepoint_ext4_drop_inode
0000000000000440 D __tracepoint_ext4_es_cache_extent
00000000000003c0 D __tracepoint_ext4_es_find_delayed_extent_range_enter
0000000000000380 D __tracepoint_ext4_es_find_delayed_extent_range_exit
0000000000000480 D __tracepoint_ext4_es_insert_extent
0000000000000340 D __tracepoint_ext4_es_lookup_extent_enter
0000000000000300 D __tracepoint_ext4_es_lookup_extent_exit
0000000000000400 D __tracepoint_ext4_es_remove_extent
0000000000000180 D __tracepoint_ext4_es_shrink
00000000000002c0 D __tracepoint_ext4_es_shrink_count
0000000000000280 D __tracepoint_ext4_es_shrink_scan_enter
0000000000000240 D __tracepoint_ext4_es_shrink_scan_exit
0000000000001800 D __tracepoint_ext4_evict_inode
0000000000000a80 D __tracepoint_ext4_ext_convert_to_initialized_enter
0000000000000a40 D __tracepoint_ext4_ext_convert_to_initialized_fastpath
0000000000000780 D __tracepoint_ext4_ext_handle_unwritten_extents
00000000000006c0 D __tracepoint_ext4_ext_in_cache
0000000000000900 D __tracepoint_ext4_ext_load_extent
0000000000000a00 D __tracepoint_ext4_ext_map_blocks_enter
0000000000000980 D __tracepoint_ext4_ext_map_blocks_exit
0000000000000700 D __tracepoint_ext4_ext_put_in_cache
0000000000000500 D __tracepoint_ext4_ext_remove_space
00000000000004c0 D __tracepoint_ext4_ext_remove_space_done
0000000000000540 D __tracepoint_ext4_ext_rm_idx
0000000000000580 D __tracepoint_ext4_ext_rm_leaf
0000000000000600 D __tracepoint_ext4_ext_show_extent
0000000000000c80 D __tracepoint_ext4_fallocate_enter
0000000000000bc0 D __tracepoint_ext4_fallocate_exit
0000000000000680 D __tracepoint_ext4_find_delalloc_range
0000000000000f00 D __tracepoint_ext4_forget
0000000000001140 D __tracepoint_ext4_free_blocks
00000000000018c0 D __tracepoint_ext4_free_inode
0000000000000100 D __tracepoint_ext4_fsmap_high_key
0000000000000140 D __tracepoint_ext4_fsmap_low_key
00000000000000c0 D __tracepoint_ext4_fsmap_mapping
0000000000000040 D __tracepoint_ext4_getfsmap_high_key
0000000000000080 D __tracepoint_ext4_getfsmap_low_key
0000000000000000 D __tracepoint_ext4_getfsmap_mapping
0000000000000740 D __tracepoint_ext4_get_implied_cluster_alloc_exit
0000000000000640 D __tracepoint_ext4_get_reserved_cluster_alloc
00000000000009c0 D __tracepoint_ext4_ind_map_blocks_enter
0000000000000940 D __tracepoint_ext4_ind_map_blocks_exit
00000000000001c0 D __tracepoint_ext4_insert_range
0000000000001400 D __tracepoint_ext4_invalidatepage
00000000000013c0 D __tracepoint_ext4_journalled_invalidatepage
0000000000001640 D __tracepoint_ext4_journalled_write_end
0000000000000880 D __tracepoint_ext4_journal_start
0000000000000840 D __tracepoint_ext4_journal_start_reserved
00000000000008c0 D __tracepoint_ext4_load_inode
0000000000000d40 D __tracepoint_ext4_load_inode_bitmap
0000000000001780 D __tracepoint_ext4_mark_inode_dirty
0000000000001000 D __tracepoint_ext4_mballoc_alloc
0000000000000f80 D __tracepoint_ext4_mballoc_discard
0000000000000f40 D __tracepoint_ext4_mballoc_free
0000000000000fc0 D __tracepoint_ext4_mballoc_prealloc
0000000000000e00 D __tracepoint_ext4_mb_bitmap_load
0000000000000dc0 D __tracepoint_ext4_mb_buddy_bitmap_load
0000000000001200 D __tracepoint_ext4_mb_discard_preallocations
0000000000001300 D __tracepoint_ext4_mb_new_group_pa
0000000000001340 D __tracepoint_ext4_mb_new_inode_pa
0000000000001280 D __tracepoint_ext4_mb_release_group_pa
00000000000012c0 D __tracepoint_ext4_mb_release_inode_pa
0000000000001900 D __tracepoint_ext4_other_inode_update_time
0000000000000c40 D __tracepoint_ext4_punch_hole
0000000000000d80 D __tracepoint_ext4_read_block_bitmap_load
0000000000001480 D __tracepoint_ext4_readpage
0000000000001440 D __tracepoint_ext4_releasepage
00000000000005c0 D __tracepoint_ext4_remove_blocks
00000000000011c0 D __tracepoint_ext4_request_blocks
0000000000001880 D __tracepoint_ext4_request_inode
0000000000001100 D __tracepoint_ext4_sync_file_enter
00000000000010c0 D __tracepoint_ext4_sync_file_exit
0000000000001080 D __tracepoint_ext4_sync_fs
00000000000007c0 D __tracepoint_ext4_trim_all_free
0000000000000800 D __tracepoint_ext4_trim_extent
0000000000000b00 D __tracepoint_ext4_truncate_enter
0000000000000ac0 D __tracepoint_ext4_truncate_exit
0000000000000b80 D __tracepoint_ext4_unlink_enter
0000000000000b40 D __tracepoint_ext4_unlink_exit
0000000000001700 D __tracepoint_ext4_write_begin
0000000000001680 D __tracepoint_ext4_write_end
00000000000014c0 D __tracepoint_ext4_writepage
00000000000015c0 D __tracepoint_ext4_writepages
0000000000001500 D __tracepoint_ext4_writepages_result
0000000000000c00 D __tracepoint_ext4_zero_range
                 U trace_print_flags_seq
                 U trace_raw_output_prep
                 U trace_seq_printf
                 U truncate_inode_pages
                 U truncate_inode_pages_final
                 U truncate_pagecache
                 U truncate_pagecache_range
                 U try_to_free_buffers
                 U try_to_release_page
                 U try_to_writeback_inodes_sb
                 U unlock_buffer
                 U unlock_new_inode
                 U unlock_page
                 U unlock_two_nondirectories
                 U unregister_filesystem
                 U unregister_shrinker
                 U up_read
                 U up_write
                 U vfs_fsync_range
                 U vfs_setpos
                 U __vmalloc
                 U vmemmap_base
                 U wait_for_completion
                 U wait_for_stable_page
                 U __wait_on_buffer
                 U wait_on_page_bit
                 U __wake_up
                 U wake_up_bit
                 U wake_up_process
                 U __warn_printk
                 U wbc_account_io
                 U write_cache_pages
                 U __x86_indirect_thunk_r10
                 U __x86_indirect_thunk_r11
                 U __x86_indirect_thunk_r14
                 U __x86_indirect_thunk_r15
                 U __x86_indirect_thunk_r8
                 U __x86_indirect_thunk_r9
                 U __x86_indirect_thunk_rax
                 U __x86_indirect_thunk_rcx

*/
