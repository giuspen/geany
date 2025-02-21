/*
 *      sidebar.h - this file is part of Geany, a fast and lightweight IDE
 *
 *      Copyright 2005 The Geany contributors
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along
 *      with this program; if not, write to the Free Software Foundation, Inc.,
 *      51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */



#ifndef GEANY_SIDEBAR_H
#define GEANY_SIDEBAR_H 1

#include "document.h"

#include "gtkcompat.h"

#ifdef GEANY_PRIVATE

G_BEGIN_DECLS

typedef struct SidebarTreeviews
{
	GtkWidget		*tree_openfiles;
	GtkWidget		*default_tag_tree;
	GtkWidget		*popup_taglist;
}
SidebarTreeviews;

extern SidebarTreeviews tv;

enum
{
	SYMBOLS_COLUMN_ICON,
	SYMBOLS_COLUMN_NAME,
	SYMBOLS_COLUMN_TAG,
	SYMBOLS_COLUMN_TOOLTIP,
	SYMBOLS_N_COLUMNS
};

enum
{
	OPENFILES_PATHS_NONE,
	OPENFILES_PATHS_LIST,
	OPENFILES_PATHS_TREE,
	OPENFILES_PATHS_COUNT
};

/* documents tree model columns */
enum
{
	DOCUMENTS_ICON,
	DOCUMENTS_SHORTNAME,    /* dirname for parents, basename for children */
	DOCUMENTS_DOCUMENT,
	DOCUMENTS_COLOR,
	DOCUMENTS_FILENAME,     /* full filename */
	DOCUMENTS_FOLD,         /* fold state stored when folding parent rows */
	DOCUMENTS_VISIBLE,
	DOCUMENTS_COLUMNS_NUM
};

void sidebar_init(void);

void sidebar_finalize(void);

void sidebar_update_tag_list(GeanyDocument *doc, gboolean update);

void sidebar_openfiles_add(GeanyDocument *doc);

void sidebar_openfiles_update(GeanyDocument *doc);

void sidebar_openfiles_update_all(void);

void sidebar_openfiles_set_filter(const gchar *filter);

void sidebar_select_openfiles_item(GeanyDocument *doc);

void sidebar_remove_document(GeanyDocument *doc);

void sidebar_add_common_menu_items(GtkMenu *menu);

void sidebar_focus_openfiles_tab(void);

void sidebar_focus_symbols_tab(void);

GtkTreeStore *sidebar_create_store_openfiles(void);
#endif

G_END_DECLS


#endif /* GEANY_SIDEBAR_H */
