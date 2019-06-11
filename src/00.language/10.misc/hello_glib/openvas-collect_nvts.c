#include <stdio.h>
#include <glib.h>

/**
 * @brief Collects all NVT files in a directory and recurses into subdirs.
 *
 * @param folder The main directory from where to descend and collect.
 *
 * @param subdir A subdirectory to consider for the collection: "folder/subdir"
 *               is thus the effective directory to descend from. "subdir"
 *               can be "" to make "folder" the effective start.
 *
 * @param files  A list that is extended with all found files. If it
 *               is NULL, a new list is created automatically.
 *
 * @return Parameter "files", extended with all the NVT files found in
 *         "folder" and its subdirectories. Not added are directory names.
 *         NVT files are identified by the defined filename suffixes.
 */
GSList *
collect_nvts (const char *folder, const char *subdir, GSList *files)
{
  GDir *dir;
  const gchar *fname;

  if (folder == NULL)
    return files;

  dir = g_dir_open (folder, 0, NULL);
  if (dir == NULL)
    return files;

  fname = g_dir_read_name (dir);
  while (fname)
    {
      char *path;

      path = g_build_filename (folder, fname, NULL);
      if (g_file_test (path, G_FILE_TEST_IS_DIR))
        {
          char *new_folder, *new_subdir;

          new_folder = g_build_filename (folder, fname, NULL);
          new_subdir = g_build_filename (subdir, fname, NULL);

          files = collect_nvts (new_folder, new_subdir, files);

          if (new_folder)
            g_free (new_folder);
          if (new_subdir)
            g_free (new_subdir);
        }
      else if (g_str_has_suffix (fname, ".nasl"))
        files = g_slist_prepend (files, g_build_filename (subdir, fname, NULL));
      g_free (path);
      fname = g_dir_read_name (dir);
    }

  g_dir_close (dir);
  return files;
}

int
main(int argc, const char *argv[])
{
    GSList *files = NULL;

    files = collect_nvts("/var/lib/openvas", "", files);
    for (GSList *iterator = files; iterator; iterator = iterator->next)
        {
                printf("%s\n", iterator->data);
        }
    return 0;
}

/* https://github.com/greenbone/openvas-scanner/blob/b955373084af612a2d8e7a92067166531df0072f/src/pluginload.c#L51 */