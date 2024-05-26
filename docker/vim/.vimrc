set nocompatible
filetype off

"Set the runtime path to include Vundle and initialize"
set rtp+=~/.vim/bundle/Vundle.vim

"Download plug-ins to the ~/.vim/plugged/ directory"

call vundle#begin('~/.vim/plugged')
	Plugin 'VundleVim/Vundle.vim'
	Plugin 'sheerun/vim-polyglot'

	Plugin 'Badacadabra/vim-archery'
	Plugin 'nordtheme/vim'
  Plugin 'junegunn/seoul256.vim'

	Plugin 'ycm-core/YouCompleteMe'
	Plugin 'preservim/nerdtree'
	Plugin 'Donaldttt/fuzzyy'
	Plugin 'tpope/vim-dispatch'

	Plugin 'airblade/vim-gitgutter'
call vundle#end()

" Fundamentals
filetype plugin indent on

set nu
syntax on

augroup numbertoggle
  autocmd!
  autocmd BufEnter,FocusGained,InsertLeave,WinEnter * if &nu && mode() != "i" | set rnu   | endif
  autocmd BufLeave,FocusLost,InsertEnter,WinLeave   * if &nu                  | set nornu | endif
augroup END

set ruler

set tabstop=2
set shiftwidth=2
set expandtab

set incsearch
set hlsearch
 
set showcmd

set termwinsize=0*0
set splitbelow
set mouse=a
  
" Theme
set t_Co=256
"	colors seoul256-light
set termguicolors
  
let mapleader = ","
set matchpairs+=<:>

" fuzzyy
let g:fuzzyy_dropdown = 1

" search under cursor
nnoremap <leader>fv :FuzzyGrep <C-R><C-W><CR>
 
" YCM
let g:ycm_show_detailed_diag_in_popup = 1
 
nnoremap <leader>jd :YcmCompleter GoTo<CR>
nnoremap <leader>jh :YcmCompleter GoToDeclaration<CR>
nnoremap <leader>jf :YcmCompleter FixIt<CR>

" Disable search highlight
nnoremap <leader>f	:noh<CR>
nnoremap <leader>s	:split<CR>

" Open NERDTree
nnoremap	<C-n>	:NERDTreeFocus<CR>

" NERDTree ignore
let NERDTreeIgnore = ['\.o$', '\.elf$', '\.map$']
